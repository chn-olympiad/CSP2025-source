#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100005],b[100005],c[100005],at,bt,ct;
long long aa,bb,cc,ans;
void dfs(int u){
	if(u>n){
		ans=max(ans,aa+bb+cc);
		return ;
	}
	if(at<n/2){
		at++;
		aa+=a[u];
		dfs(u+1);
		at--,aa-=a[u];
	}
	if(bt<n/2){
		bt++;
		bb+=b[u];
		dfs(u+1);
		bt--,bb-=b[u];
	}
	if(ct<n/2){
		ct++;
		cc+=c[u];
		dfs(u+1);
		ct--,cc-=c[u];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		aa=at=0,bb=bt=0,cc=ct=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}
