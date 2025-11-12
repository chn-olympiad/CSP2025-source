#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;
ll n,q,l[N][4],l1,l2;
string s[N][4],t[N][4];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1];
		cin>>s[i][2];
		l[i][1]=s[i][1].find('b');
		l[i][2]=s[i][2].find('b');
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1];
		cin>>t[i][2];
		l1=t[i][1].find('b');
		l2=t[i][2].find('b');
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(l1<l[i][1]&&l1-l[i][1]==l2-l[i][2])ans+=l1-l[i][1];
	}
	cout<<ans;
	return 0;
}
