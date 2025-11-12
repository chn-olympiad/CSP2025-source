#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k,a[N][110],b[N][110],c[N],ans[25],l[25];
void f(int k,int x){
	int sum=1;
	while(x!=0){
		a[k][sum]=x%2;
		x/=2;sum++;
	}if(sum==1)sum++;
	c[k]=sum-1;
}void add(int k,int m){
	int len=max(c[k],c[m]);
	for(int i=1;i<=len;i++){
		if(a[k][i]==1&&b[m][i]==1)b[k][i]=0;
		else b[k][i]+=a[k][i]+b[m][i];
	}c[k]=len;
}int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int sum=1,num=0,val=0;
	while(k!=0){
		ans[sum]=k%2;
		k/=2;sum++;
	}sum-=1;
	memset(a,0,sizeof a);
	c[0]=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		f(i,x);add(i,i-1);
	}for(int i=1;i<=n;i++){
		for(int j=val;j<i;j++){
			int len=max(c[i],c[j]);
			for(int k=1;k<=len;k++){
				if(b[i][k]==1&&b[j][k]==1)l[k]=1;
				else l[k]=b[i][k]+b[j][k];
			}
			bool b=1;
			for(int k=1;k<=len;k++)
				if(ans[k]!=l[k]){
					b=0;break;
				}
			if(b){
				num++,val=i,b=1;
				break;
			}
		}
	}cout<<num<<endl;
	return 0;
}
