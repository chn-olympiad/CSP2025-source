#include<bits/stdc++.h>
#define lo long long
using namespace std;
lo n,m,ans;
string s[200010],q[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(lo i=1;i<=n;i++) cin>>s[i]>>q[i];
	while(m--){
		string a,b;
		ans=0;
		cin>>a>>b;
		for(lo i=1;i<=n;i++){
			for(lo start=0;start<=a.size()-s[i].size();start++){
				string x,z;
				bool flag=true;
				for(lo y=start,wei=0;y<start+s[i].size();y++,wei++){
					if(a[y]!=s[i][wei]){
						flag=false;
						break;
					}
				}
				if(flag==true){
					for(lo xs=0;xs<start;xs++) x+=a[xs];
					for(lo zs=start+s[i].size();zs<a.size();zs++) z+=a[zs];
					string last=x+q[i]+z;
					bool fag=true;
					for(lo j=0;j<a.size();j++){
						if(last[j]!=b[j]){
							fag=false;
							break;
						}
					}
					if(fag==true){
						ans++;
						break;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
