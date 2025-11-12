#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		int lent=t1.length();
		for(int i=1;i<=n;i++){
			int lens=s1[i].length();
			for(int j=0;j<lent;j++){
				if(j+lens-1<lent){
					string nstr=t1.substr(0,j)+s2[i]+t1.substr(j+lens,lent-j-lens);
					if(t1.substr(j,lens)==s1[i]&&nstr==t2)
						ans++;
				}
			}
		} 
		cout<<ans<<endl;
	} 
	return 0;
} 
