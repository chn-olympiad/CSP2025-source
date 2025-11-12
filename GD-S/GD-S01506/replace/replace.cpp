#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string a[200005],b[200005];
signed main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++)
    	cin>>a[i]>>b[i];
    while (q--) {
    	string t1,t2;
    	cin>>t1>>t2;
    	int ans=0;
    	for (int i=1;i<=n;i++) {
            int l=t1.find(a[i]);
            if (l!=-1) {
                int r=-1;
                string t="";
                for (int j=l;j<t1.size();j++) {
                    t+=t1[j];
                    if (t==a[i]) {
                        r=j;
                        break;
                    }
                }
                string x="",z=""; 
                if (l!=0) x=t1.substr(0,l);
                if (r!=t1.size()) z=t1.substr(r+1);
                ans+=(x+b[i]+z==t2);
            }
    	}
    	cout<<ans<<'\n';
	}
	return 0;
}
