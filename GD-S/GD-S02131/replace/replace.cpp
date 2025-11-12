#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define For(a,b,c) for(int a=b;a<=c;a++)
#define Fro(a,b,c) for(int a=b;a>=c;a--)
#define int long long
using namespace std;
using namespace __gnu_pbds;
const int N=1e5+5;
string s[N][3],p[3];
int n,q,ans;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	For(i,1,n)
		cin>>s[i][1]>>s[i][2];
	For(i,1,q){
		ans=0;
		cin>>p[1]>>p[2];
		For(j,0,p[1].size()-1){
			For(k,1,n){
//				cout<<p[1].substr(j,s[k][1].size())<<" "<<p[2].substr(j,s[k][2].size())<<'\n';
				if(p[1].substr(j,s[k][1].size())==s[k][1]&&p[2].substr(j,s[k][2].size())==s[k][2]){
					string s1=p[1].substr(0,j)+s[k][2]+p[1].substr(j+s[k][1].size());
//					cout<<s1<<" "<<s1.size()<<" "<<p[2]<<" "<<p[2].size()<<'\n';
					if(s1==p[2])
						ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
