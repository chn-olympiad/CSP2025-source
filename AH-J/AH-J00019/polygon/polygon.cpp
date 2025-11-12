#include<bits/stdc++.h>
using namespace std;
int a[5001];
int al,n;
void dfs(int i,int s,int x,int z,bool t){
	if(x*2<s&&z>=3){
		al+=t;
	}
	if(i==n+1)return ;
	dfs(i+1,s+a[i],max(x,a[i]),z+1,true);
	if(n-i+z>=3)
	dfs(i+1,s,x,z,false);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int mx=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	if(mx==1){
		long long ans=0;
		for(int i=3;i<=n;i++){
			long long ss=1;
			for(int j=1;j<=i;j++){
				ss*=(n-j+1);ss/=j;
				ss%=998244353;
			}
		}
		cout<<ans<<"\n";
	}else{
		dfs(1,0,0,0,0);
		cout<<al<<"\n";
	}
	return 0;
}
