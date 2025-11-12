#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int T;
int n;
int a[N][4];
int w;
ll ans=0;
struct po{
	int sum,id;
};
po cu1[N];
po cu2[N];
po cu3[N];
void fun(int u,int sum,int c1,int c2,int c3){
	if(ans<sum){
		ans=sum;
	}
	if(u>n) return ;
	if(c1>0){
		fun(u+1,sum+a[u][1],c1-1,c2,c3);
	}
	
	if(c2>0){
		fun(u+1,sum+a[u][2],c1,c2-1,c3);
	}
	
	if(c3>0){
		fun(u+1,sum+a[u][3],c1,c2,c3-1);
	}
	return ;
}
bool cmp(po x,po y){
	return x.sum>y.sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T; 
	while(T--){
		cin>>n;
		w=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1];
			cin>>a[i][2];
			cin>>a[i][3];
			cu1[i].sum=a[i][1];
			cu2[i].sum=a[i][2];
			cu3[i].sum=a[i][3];
			
			cu1[i].id=i;
			cu2[i].id=i;
			cu3[i].id=i;
		}
	ans=0;
	if(n<=30){//小样例 
		fun(1,0,w,w,w);
		cout<<ans<<endl;
		
	}	
 	else {
 		int flag1=0;//		特殊测试点
		int flag2=0;
		for(int i=1;i<=n;i++){
			if(a[i][2]!=0){
				flag1=1;
				break;
			}
			if(a[i][3]!=0){
				flag1=flag2=1;
				break;
			}
		}
		if(flag1==1){
			sort(cu1+1,cu1+1+n,cmp);
			for(int i=1;i<=w;i++){
				ans+=cu1[i].sum;
			}
			cout<<ans;
			}
		 }	
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

