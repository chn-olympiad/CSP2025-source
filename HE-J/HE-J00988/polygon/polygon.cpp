#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0;
int n;
int a[100000];
int ac(int v,int s,int m,int y){
	if(s-m>m&&v>=3&&s!=y){
		ans++;
	}if(v>=n+1){
		return 0;
	}v+=1;
	ac(v,s+a[v],a[v],s);
	ac(v,s,m,s);
	return 0;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	ac(0,0,0,0);
	cout<<ans<<endl;
	return 0;
}
