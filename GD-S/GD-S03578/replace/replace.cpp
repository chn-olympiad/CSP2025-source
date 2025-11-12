#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,ans;
struct rep{
	string s1,s2;
}a[200010];
string t1,t2,t3,t4;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i].s1>>a[i].s2;
	while(q--){
		ans=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			t3=t1,t4=t2;
			ll siz=a[i].s1.size(),x=t3.find(a[i].s1);
			while(x!=-1){
				if(t3.substr(x,siz)==t4.substr(x,siz)){
					t3.replace(x,siz,a[i].s2);
					t4.replace(x,siz,a[i].s2);
				}else{
					t3.replace(x,siz,a[i].s2);
					if(t3==t4) ans++;
					break;
				}
				x=t3.find(a[i].s1);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

