//B 25pts
#include<bits/stdc++.h>
#define int long long
#define rint register int
#define endl '\n'
using namespace std;
const int N=2e5+5;
int pos1[N],pos2[N],s[N];
string s1,s2;
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	for(rint i=1;i<=n;++i){
		cin>>s1>>s2;
		pos1[i]=s1.find('b');
		pos2[i]=s2.find('b');
		s[i]=s1.size();
	}
	while(q--){
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			cout<<0;
			continue;
		}
		int p1=s1.find('b'),p2=s2.find('b'),size=s1.size(),ans=0;
		for(rint i=1;i<=n;++i){
			if(s[i]>size) continue;
			if(p1-p2==pos1[i]-pos2[i]&&p1>=pos1[i]&&s[i]-pos1[i]<=size-p1)
				++ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}
