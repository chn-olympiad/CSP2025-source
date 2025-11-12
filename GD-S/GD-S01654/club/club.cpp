#include<bits/stdc++.h>
using namespace std;
int n,q[205][3],ans=INT_MIN,T;
void fin(int x,int a,int b,int c,int m){
	if(a>n/2)return ;
	if(b>n/2)return ;
	if(c>n/2)return ;
	if(x==n+1){
		ans=max(m,ans);
	}
	fin(x+1,a+1,b,c,m+q[x][1]);
	fin(x+1,a,b+1,c,m+q[x][2]);
	fin(x+1,a,b,c+1,m+q[x][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=INT_MIN;
		for(int i=1;i<=n;i++)cin>>q[i][1]>>q[i][2]>>q[i][3]; 
		fin(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
