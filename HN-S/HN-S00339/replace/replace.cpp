#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,q;
string s[N][2],t1,t2;
int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>q;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		// int a0=0,a1=0,b0=0,b1=0;
		// for(int j=0;j<s[i][0].size();j++){
		// 	if(s[i][0][j]=='a') a0++;
		// 	if(s[i][1][j]=='a') a1++;
		// 	if(s[i][0][j]=='b') b0++;
		// 	if(s[i][1][j]=='b') b1++;
		// }
		// if(a0+b0!=s[i][0].size()||a1+b1!=s[i][1].size()||b0!=1||b1!=1) f=1;
	}
	while(q--){
		cin>>t1>>t2;
		int l1=t1.size(),ans=0;
		for(int i=0;i<l1;i++){
			for(int j=1;j<=n;j++){
				int l2=s[j][0].size();
				if(i+l2-1>=l1) continue;
				if(t1.substr(i,l2)!=s[j][0]) continue;
				string tmp;
				if(i>0) tmp=t1.substr(0,i);
				tmp=tmp+s[j][1];
				if(i+l2<l1) tmp=tmp+t1.substr(i+l2,l1-(i+l2));
				if(tmp==t2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}