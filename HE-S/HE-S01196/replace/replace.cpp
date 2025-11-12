#include<bits/stdc++.h>
using namespace std;
const int N=2e5+500;
string a[N];
map <string,string> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		a[i]=x;
		mp[x]=y;
	}
	for(int i=1;i<=q;i++){
		string s,t;
		cin>>s>>t;
		int ans=0;
		string u=s;
		for(int j=0;j<s.size();j++){
			for(int k=1;k<=n;k++){
				int tag=1;
				for(int l=0;l<a[k].size();l++){
					if(s[j+l]!=a[k][l]){
						tag=0;
						break;
					}
				}
				if(tag){
					string o=mp[a[k]];
					for(int l=0;l<o.size();l++){
						s[j+l]=o[l];
					}
				}
			}
			if(s==t)ans++;
			s=u;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
