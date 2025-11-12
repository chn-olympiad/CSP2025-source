#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,ans,kl[N];
string s[N],sx[N];
string y,sy;
inline bool f(int x)
{
	int l=y.find(s[x]),ly=y.size();
	if(l==-1){
		return 0;
	}
	string hx="";
	for(int i=0;i<l;i++){
		hx+=y[i];
	}
	for(int i=0;i<kl[x];i++){
		hx+=sx[x][i];
	}
	for(int i=l+kl[x];i<ly;i++){
		hx+=y[i];
	}
	return hx==sy;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>sx[i];
		kl[i]=s[i].size();
	}
	while(q--){
		cin>>y>>sy;
		ans=0;
		for(int i=1;i<=n;i++){
			if(f(i)){
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
