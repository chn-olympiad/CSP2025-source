#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string s1[200005],s2[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>s1[i]>>s2[i];
	while(q--){
		int len1,len2,ans=0;
		string t1,t2;
		cin>>t1>>t2;
		len1=t1.size();
		len2=t2.size();
		t1=' '+t1+' ';
		for(int cnt=1;cnt<=len1;++cnt){
			for(int i=cnt;i<=len1;++i){
				int j=i-cnt+1;
				string x,y,z,p;
				for(int t=1;t<j;++t) x+=t1[t];
				for(int t=j;t<=i;++t) y+=t1[t];
				for(int t=i+1;t<=len1;++t) z+=t1[t];
				for(int k=1;k<=n;++k)
					if(s1[k]==y){
						y=s2[k];
						break;
					}
				p=x+y+z;
				if(p==t2) ++ans;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
