#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q,ans;
ll c[200005];
string s[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		c[i]=s[i][0].size();
		s[i][0]=' '+s[i][0];
		s[i][1]=' '+s[i][1];
	}
	while(q--){
		string a,b,x,y;
		cin>>a>>b;
		ll len=a.size();
		a=' '+a;
		b=' '+b;
		ll l,r;
		for(int i=1;i<=len;i++){
			if(a[i]!=b[i]) break;
			l=i;
		}
		for(int i=len;i;i--){
			if(a[i]!=b[i]) break;
			r=i;
		}
		for(int i=l;i<=r;i++) x+=a[i],y+=b[i];
		for(int i=1;i<=n;i++){
			if(s[i][0]==x&&s[i][1]==y) ans++;
		}
		cout<<"0\n";
		ans=0;
	}
	return 0;
}
