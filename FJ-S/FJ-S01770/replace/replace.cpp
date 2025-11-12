#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[200005],s2[200005];
string qq1,qq2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		ans=0;
		cin>>qq1>>qq2;
		for(int i=1;i<=n;i++){
			int x=0;
			while(qq1.find(s1[i],x)!=-1){
				x=qq1.find(s1[i],x);
				string now=qq1.substr(0,x)+s2[i]+qq1.substr(x+s1[i].size());
				if(now==qq2){
					ans++;
					break;
				}
				x++;
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
} 
/*4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
