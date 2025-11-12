#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
#define V vector
#define pii pair<ll,ll>
#define P priority_queue
typedef long long ll;
const int N=1e6+10;
ll T,n,q,ans;
string a[N],b[N],s1,s2;
map<string,string>mp;
void check(string k){
	for(int i=0;i<k.size();i++){
		for(int j=1;j<=k.size()-i;j++){
			if(mp.count(k.substr(i,j))){
				if(k.substr(0,i)+mp[k.substr(i,j)]+k.substr(i+j)==s2)ans++;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		mp[a[i]]=b[i];	
	}
	while(q--){
		cin>>s1>>s2;
		if(s1==s2||s1.size()!=s2.size())cout<<0<<endl;
		ans=0;
		check(s1);
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 3
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
abbc cdde
*/

