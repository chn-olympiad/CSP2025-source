#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,q,a[N],b[N];
string s;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<s.size();j++){
			if(s[j]=='b'){
				a[i]=j;
				b[i]=s.size()-j;
				break;
			}
		}
	}
	while(q--){
		cin>>s;
		int ans=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='b'){
				for(int j=1;j<=n;j++){
					if(a[j]>=i&&b[j]<=s.size()-i){
						ans++;
					}
				}
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
