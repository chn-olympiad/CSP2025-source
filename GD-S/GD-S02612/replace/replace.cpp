#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
string s[N][2];
int a[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1],a[i]=s[i][0].length();
	for(int i=1;i<=q;i++){
		ll ans=0;
		string t1,t2;
		cin>>t1>>t2;
		int l=t1.length();
		for(int i=1;i<=n;i++){
			for(int j=0;j<=l-a[i];j++){
				if(t1.substr(j,a[i])==s[i][0] && t1.substr(0,j)+s[i][1]+t1.substr(j+a[i],l-j-a[i])==t2)
					ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
