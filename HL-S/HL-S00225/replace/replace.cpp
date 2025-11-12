
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
map<string,vector<string> > dict;
string s1,s2;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string sa,sb;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		dict[s1].push_back(s2);
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>sa>>sb;
		for(int rx=0;rx<=n;rx++){
			string tmp1,tmp2;
			for(int l=0;l<=rx;l++){
				tmp1+=sa[l-1];
				tmp2+=sb[l-1];
				if(tmp1!=tmp2) break;
			}
			for(int ry=1;ry<=n;ry++){
				string tmp3,tmp4,tmp5,tmp6;
				for(int l=ry+1;l<=n;l++){
					tmp3+=sa[l-1];
					tmp4+=sb[l-1];
					if(tmp3!=tmp4) goto ed;
				}
				for(int ll=rx+1;ll<=ry;ll++){
					tmp5=tmp5+sa[ll-1];
					tmp6=tmp6+sb[ll-1];
				}
				if(tmp5!=tmp6) goto ed;
				for(int k=0;k<dict[tmp5].size();k++){
					if(tmp6==dict[tmp5][k]){
						ans++;
					}
				}
				ed :;
			}
			
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
