#include <bits/stdc++.h>
using namespace std;
const int N=5e2+20;
int n,m;
int a[N],p[N],s[N];
int ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char t;
		cin>>t;
		if(t=='1') a[i]=0;
		else a[i]=1;
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		p[i]=n-t+1;
	}
	cout<<ans;
	return 0;
}

