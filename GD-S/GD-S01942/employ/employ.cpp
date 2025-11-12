#include<bits/stdc++.h>
using namespace std;
const int N=510,inf=1e9+10;

bool s[N];
int n,m,p[N],a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	char c;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>c,s[i]=c-'0';
	for(int i=1;i<=n;++i)
		cin>>a[i],p[i]=i;
	int ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;++i)
			if(!s[i]||cnt>=a[p[i]])++cnt;
		if(n-cnt>=m)++ans;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
