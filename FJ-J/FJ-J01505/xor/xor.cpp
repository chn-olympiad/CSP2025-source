#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
map<int,int> mp;
int a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int now=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		now^=a[i];
		int csl=now;
		csl^=k;
		if(mp[csl]||now==k){
			ans++;
			now=0;
			mp.clear();
			continue;
		}
		else {
			mp[now]=i;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
