//GZ-S00203 盘州市第二中学 景文博
#include<bits/stdc++.h>
using namespace std;
int T;
int n;
struct student{
	int a,b,c;
};
int a1=0,b1=0,c1=0;
long long ans=0;
long long l=0;

student f[100005];
void dfs(int u){
	if(u==n+1){
		ans=max(ans,l);
		return;
	}
	if(a1<n/2){
		l+=f[u].a;a1++;
		dfs(u+1);
		l-=f[u].a;a1--;
	}
	if(b1<n/2){
		l+=f[u].b;b1++;
		dfs(u+1);
		l-=f[u].b;b1--;
	}
	if(c1<n/2){
		l+=f[u].c;c1++;
		dfs(u+1);
		l-=f[u].c;c1--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
	  cin>>n;
	  ans=0;a1=0;b1=0;c1=0;l=0;
	  for(int i=1;i<=n;i++){
	  	cin>>f[i].a>>f[i].b>>f[i].c;
	  }
	  dfs(1);
	  cout<<ans<<endl;
	}
	return 0;
}
