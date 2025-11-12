#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N],ss[N];
string t,tt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>ss[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>t>>tt;
		for(int i=1;i<=n;i++){
			if(tt.find(ss[i])==0){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
