#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,L=5e6+1;
int n,q,d[N],cnt[L<<1];
string s[3],t[3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[1]>>s[2];
		d[i]=s[2].find('b')-s[1].find('b');
		cnt[d[i]+L]++;
	}
	while(q--){
		cin>>t[1]>>t[2];
		if(t[1].size()!=t[2].size())cout<<0<<endl;
		else cout<<cnt[t[2].find('b')-t[1].find('b')+L]<<endl;
	}
	return 0;
}
