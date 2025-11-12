#include<iostream>
#include<algorithm>
using namespace std;
int n,n2;
int T;
long long ans;
int a[10][100005]; 

void dfs(int i,long long s,int t1,int t2,int t3){
	if(i>n){
		if(s>ans) ans=s;
		return ;
	}
	if(t1<n2)dfs(i+1,s+a[1][i],t1+1,t2,t3);
	if(t2<n2)dfs(i+1,s+a[2][i],t1,t2+1,t3);
	if(t3<n2)dfs(i+1,s+a[3][i],t1,t2,t3+1);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	//cout<<1;
	while(T--){
		cin>>n;
		n2=n/2;
		//cout<<n2;
		for(int i=1;i<=n;++i){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
		
	}
	
	return 0;
} 
