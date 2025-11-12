#include<bits/stdc++.h>
using namespace std;
int a[500050][8],q[500050][8],cnt[8];
struct TTT{
	int x,y;
}T[500050];
bool cmp(TTT aaa,TTT bbb){
	return aaa.y<bbb.y;
}
void ejz(int x,int id){
	int tot=7;
	while(x!=0){
		a[id][tot--]=x%2;
		x=(x-x%2)/2;
	}
}
void qzh(int id){
	for(int i=1;i<=7;i++)
		q[id][i]=q[id-1][i]+a[id][i];
} 
int count(int i,int j){
	int sum=0;
	for(int k=1;k<=7;k++){//k为位数 
		cnt[k]=q[j][k]-q[i-1][k];
		cnt[k]=cnt[k]%2;
		sum=sum*10+cnt[k];
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,total=0,ans=0;cin>>n>>k;
	ejz(k,0);//a[0]为k的二进制 
	for(int i=1;i<=7;i++)ans=ans*10+a[0][i];//ans为k的二进制转化为10进制 
	for(int i=1;i<=n;i++){
		int l;cin>>l;
		ejz(l,i);//将l转化为2进制存在a里 
		qzh(i);//各位前缀和
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=count(i,j);
			if(sum==ans){
				T[++total].x=i;
				T[total].y=j;
				break;
			}
		}
	}
	sort(T+1,T+total+1,cmp);
	int now=-1,ans2=0;
	for(int i=1;i<=total;i++){
		if(T[i].x>now){
			ans2++;
			now=T[i].y;
		}
	}
	cout<<ans2<<endl;
	return 0;
}
