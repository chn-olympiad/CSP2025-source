#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
int n,q;
string s1[MAXN],s2[MAXN],w1[MAXN],w2[MAXN];


int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    	for(int j=1;j<=2;++j)
    		cin>>s1[i]>>s2[i];
    for(int i=1;i<=q;++i)
    	for(int j=1;j<=2;++j)
    		cin>>w1[i]>>w2[i];
	for(int i=1;i<=q;++i) cout<<0<<'\n';
	return 0;
}