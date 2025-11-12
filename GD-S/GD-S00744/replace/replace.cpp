#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,ans,l,z,y,g[200005],bj[200005];
string s[200005][2],t[2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1],g[i]=s[i][0].size();
	}for(ll c=1;c<=q;c++){
		cin>>t[0]>>t[1];
		ans=0;
		l=t[0].size();
		if(l!=t[1].size()){
			cout<<"0\n";
			continue;
		}z=l,y=0;
		for(ll i=0;i<l;i++){
			if(t[0][i]!=t[1][i]){
				if(z>=l)z=i;
				y=i;
			}
		}for(ll i=z;i>=0;i--){
			for(ll j=1;j<=n;j++){
				if(bj[j]==c||g[j]<=y-i||g[j]>l-i)continue;
				ll k=0;
				while(s[j][0][k]==t[0][i+k]&&s[j][1][k]==t[1][i+k]&&k<g[j])k++;
				if(k==g[j])ans++,bj[j]=c;
			}
		}cout<<ans<<endl;
	}return 0;
}
