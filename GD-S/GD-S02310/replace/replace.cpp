#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200010;
int n,q;
string s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q--){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			puts("0");
			continue;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(int)a.size();j++){
				if(j+(int)s[i][0].size()-1>=(int)a.size())break;
				bool flag=1;
				for(int k=0;k<(int)s[i][0].size();k++){
					if(s[i][0][k]!=a[k+j]){
						flag=0;
						break;
					}
				}
				if(!flag)continue;
				string x=a;
				for(int k=0;k<(int)s[i][1].size();k++)x[k+j]=s[i][1][k];
				if(x==b)ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
