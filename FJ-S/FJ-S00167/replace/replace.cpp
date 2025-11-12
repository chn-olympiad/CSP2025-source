#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005],p[200005],e[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,c;
		int x,y;
		cin>>s>>c;
		for(int i=0;i<s.size();i++){
			if(s[i]=='b'){
				x=i;
				break;
			}
		}
		for(int i=0;i<c.size();i++){
			if(c[i]=='b'){
				y=i;
				break;
			}
		}
		a[i]=x-y;
		b[i]=s.size();
		p[i]=x;
		e[i]=s.size()-x-1;
	}
	while(q--){
		string t,l;
		int c,d;
		long long ans=0;
		cin>>t>>l;
		for(int i=0;i<t.size();i++){
			if(t[i]=='b'){
				c=i;
				break;
			}
		}
		for(int i=0;i<l.size();i++){
			if(l[i]=='b'){
				d=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(c-d==a[i]&&t.size()>=b[i]&&c>=p[i]&&t.size()-c-1>=e[i]) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
