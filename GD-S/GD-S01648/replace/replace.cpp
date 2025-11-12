#include<iostream>
#include<string>
using namespace std;
const int maxn=2e5+10;
int n,q;
string s[maxn][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		int start,end;
		for(int j=0;j<a.size();j++){
			if(a[j]!=b[j]){
				start=j;
				break;
			}
		}
		for(int j=a.size()-1;j>=0;j--){
			if(a[j]!=b[j]){
				end=j;
				break;
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			for(int where=0;where<=((long long)(a.size()-s[j][0].size()))&&where<=start&&end<=where+s[j][0].size();where++){
				bool ok=1;
				for(int k=where;k<s[j][0].size()+where;k++){
					if(s[j][0][k-where]!=a[k]||s[j][1][k-where]!=b[k]){
						ok=0;
						break;
					}
				}
				if(ok)ans++;
			}
		}
		cout<<ans<<endl;
	}
}
