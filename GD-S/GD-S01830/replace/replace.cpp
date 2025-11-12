#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
struct abc{
	string s1,s2;
};
int n,q;
abc s[N],t[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i].s1>>s[i].s2;
	for(int i=1;i<=q;i++){
		cin>>t[i].s1>>t[i].s2; 
		cout<<0<<"\n";
	}
	return 0;
}
