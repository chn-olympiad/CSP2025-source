#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s[N],g[N];
map<string,string> m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>g[i];
		m[s[i]]=g[i];
	}
	for(int i=1;i<=q;i++){
		string t,k;
		cin>>t>>k;
		if(t.size()!=k.size()){
			cout<<0<<endl;
			continue;
		}
		else{
			int ans=0;
			for(int i=0;i<t.size();i++){
				for(int len=1;len+i<=t.size();len++){
					int j=i+len-1;
					string v=t.substr(i,j-i+1);
					string c=k.substr(i,j-i+1);
					//cout<<t.substr(0,i)<<" "<<v<<" "<<t.substr(j+1,n-j)<<" "<<i<<" "<<j<<endl; 
					//cout<<t.substr(0,i-1)+m[v]+t.substr(j+1,n-1)<<endl;
					if(v!=c&&m[v]==c&&t.substr(0,i)+m[v]+t.substr(j+1,n-j)==k){
						ans++;
						//cout<<"T"<<endl;	
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
