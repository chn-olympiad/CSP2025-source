#include<bits/stdc++.h>
#define int long long
using namespace std;
// string s[5000005][2],t[5000005][2];
int c[505],f[505],pd[505];
int n,m,ans=0;
string s;
void dfs(int x,int ju){
	if(x==n+1){
		// cout<<ju<<"   ";for(int i=1;i<=n;i++)cout<<f[i]<<" ";cout<<"\n";
		if(n-ju>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!pd[i]){
			if(ju>=c[i]){
				pd[i]=1;
				f[x]=i;
				dfs(x+1,ju+1);
				pd[i]=0;
			}
			else{
				pd[i]=1;
				f[x]=i;
				if(s[x]=='1')
					dfs(x+1,ju);
				else 
					dfs(x+1,ju+1);
				pd[i]=0;
			}
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	// cout<<n<<" "<<m<<"\n";
	for(int i=1;i<=n;i++)cin>>c[i];
	// cout<<"?";
	dfs(1,0);
	cout<<ans;
	return 0;
}