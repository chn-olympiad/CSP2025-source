#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,t;
struct node{
	string s1,s2;
}s[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>s[i].s1>>s[i].s2;
		t++;
	}
	while(q--){
		int ans=0;
		string a,b;
		cin>>a>>b;
		for(int i=0;i<=t;++i){
			for(int l=0,r=s[i].s1.size()-1;l<=r;){
				
			}
		}cout<<ans;
	}
	return 0;
}
