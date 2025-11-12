#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
string a[MAXN];
string b[MAXN];
int n,q,l,f,ans;
string s1,s2,sn;
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while (q--){
		cin>>s1>>s2;
		f=0;
		ans=0;
		for (int i=1;i<=n;i++){
			l=a[i].size();
			for (int j=0;j<s1.size();j++){
				if (a[i][f]!=s1[j]){
					f=0;
					continue;
				}
				
				f++;
				if(f==l){
					sn=s1;
					for (int h=j-l+1;h<=j;h++){
						sn[h]=b[i][h-(j-l+1)];
					}
					if (sn==s2){
						ans++;
					}
					sn=s1;
					f=0;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
/*
Ren5Jie4Di4Ling5%
4 2
xabcx xadex
ab cd
bc de
bcx dex
xabcx xadex
aaaa bbbb
*/
