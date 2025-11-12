#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

const int N = 1e6+5;

int n,Q;
string s[N][2];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];

	while(Q--){
		string a,b;
		cin>>a>>b;
		int m=a.size();
		
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j+s[i][0].size()-1<m;j++){
				string k=a.substr(j,s[i][0].size());
				if(k==s[i][0]){
					string k1=a.substr(0,j),k2=a.substr(j+s[i][0].size(),m-j-s[i][0].size());
					string p=k1+s[i][1]+k2;
					if(p==b)ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

