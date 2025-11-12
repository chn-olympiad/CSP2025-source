#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s1[N],s2[N],a,b;
bool pd(int p,string z,string x,string c,string v){
	z.replace(p,c.size(),v);
	if(z==x) return 1;
	else return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	while(q--){
		int ans=0;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			int k=a.find(s1[i]);
			if(k==-1) break;
			else ans+=pd(k,a,b,s1[i],s2[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
