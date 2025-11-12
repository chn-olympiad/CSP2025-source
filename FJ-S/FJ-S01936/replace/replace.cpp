#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
struct node{
	string a,b;
}s[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>s[i].a>>s[i].b;
	while(q--){
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		for(int i=0;i<n;i++){
			int len=s[i].a.size();
			for(int j=0;j<t1.size();j++)
				if(t1.substr(j,j+len)==s[i].a){
					t1.substr(j,j+len)=s[i].a;
					break;
				}
			if(t1==t2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
