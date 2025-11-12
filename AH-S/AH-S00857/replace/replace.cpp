#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7,inf=1e18;
int q,n,ans;
string s1[N],s2[N],t1[N],t2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		int o=s1[i].size();
		ans=0;
		for(int l=0;l<o;l++){
			string m="";
			for(int r=l;r<o;r++){
				m+=s1[r];
				string y="";
				for(int h=1;h<=n;h++){
					if(t1[h]==m){
						y=t2[h];
						string x="",z="";
						for(int k=0;k<l;k++) x+=s1[k];
						for(int k=r+1;k<o;k++) z+=s1[k];
						string op="";
						op+=x;
						op+=y;
						op+=z;
						if(op==s2[i]) ans++;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	// I love China , NOI and CCF!
	return 0;
}
