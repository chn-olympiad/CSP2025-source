#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,l,ans;
string a,b;
map<string,string> m;
bool v[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>a>>b,m[a]=b;
	while(q--){
		cin>>a>>b;ans=0;
		int l=a.length(),bl=b.length();
		if(l!=bl){printf("%d\n",0);continue;}
		string x="";
		for(int i=0;i<l;++i){
			string y="";
			for(int j=i;j<l;++j){
				y+=a[j];
				if(m[y].length()){
					string z="";
					for(int d=j+1;d<l;++d) z+=a[d];
					if(x+m[y]+z==b) ++ans;
				}
			}
			x+=a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
