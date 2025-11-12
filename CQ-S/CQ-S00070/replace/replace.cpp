#include<bits/stdc++.h>
#define ll long long 
using namespace std; 
string s1[40001],s2[40001],s,xs,ys,ss,sss,ks,js,anss,anss1;
int n,q,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		cin>>xs>>ys;
		ans=0;
		s=ss="";
		xs=" "+xs;
		ys=" "+ys;
		anss="";
		ks="";
		js="";
		bool g=0;
		int l=0,r=0;
		for(int i=1;i<=xs.size();i++){
			if(xs[i]!=ys[i]&&g==0){
				g=1;
				s+=xs[i];
				l=i;
				ss+=xs[i];
				continue;
			}
			if(g)ss+=xs[i];
			if(xs[i]!=ys[i]){
				s=ss;
				r=i;
			}
		}
		for(int i=l;i<=r;i++)sss+=ys[i];
		for(int i=l;i>=1;i--){
			js="";
			if(i!=l)ks=xs[i]+ks;
			for(int k=r;k<=xs.size();k++){
	            if(k!=r)js+=xs[k];	
				anss=ks+s+js;
				anss1=ks+sss+js;
				for(int j=1;j<=n;j++)if(s1[j]==anss&&s2[j]==anss1)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} /*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
