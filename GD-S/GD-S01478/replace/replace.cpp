#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,qq,hh,ans;
string s[200010][2],t[200010][2];
void check(ll u,ll v){
	for(int i=0;i<t[u][0].length()-s[v][0].length()+1;i++){
		bool flag=0;
		for(int j=0;j<s[u][0].length();j++){
			if(t[u][0][i+j]!=s[v][0][j]||t[u][1][i+j]!=s[v][1][j]){
				flag=1;
				break;
			}
		}
		if(flag==0&&i-1<=qq&&hh<=i+s[u][0].length()){
			ans++;
		}
	}
}
void query(ll u){
	for(int i=1;i<=n;i++){
		check(u,i);
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][0]>>t[i][1];
	}
		for(int i=1;i<=q;i++){
			if(t[i][1].length()!=t[i][0].length()){
				cout<<"0\n";
				continue;
			}else{
				for(int j=0;j<t[i][1].length();j++){
					if(t[i][1][j]!=t[i][0][j]){
						qq=j-1;
						break;
					}
				}
				for(int j=t[i][1].length();j>=0;j--){
					if(t[i][1][j]!=t[i][0][j]){
						hh=j+1;
						break;
					}
				}
				ans=0;
				query(i);
				cout<<ans<<"\n";
			}
		}
} 


