#include<bits/stdc++.h>
using namespace std;
string s[200005][5];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1; i<=q; i++){
		int ans=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int j=1; j<=n; j++){
			if(t1==s[j][1]&&t2==s[j][2]){
				ans++;
			}
		}
		int l=0,r=0,f=0;
		for(int j=0; j<t1.size(); j++){
			if(t1[j]!=t2[j]&&f==0){
				l=j;
				f=1;
				continue;
			}
			if(t1[j]!=t2[j]){
				r=j;
			}
		}
		string c,d;
		for(int j=l; j<=r; j++){
			c+=t1[j];
			d+=t2[j];
		}
		for(int j=1; j<=n; j++){
			if(s[j][1]==c&&s[j][2]==d){
				ans++;
				break;
			}
		}
		cout<<ans<<'\n';
	}
//	for(int i=1; i<=q; i++){
//		cout<<0<<endl;
//	}
	return 0;
} 