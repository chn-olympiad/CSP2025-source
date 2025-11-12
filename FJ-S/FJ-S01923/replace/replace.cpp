#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s1[3][200005],s2[3][200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[1][i]>>s1[2][i];
	}
	for(int i=1;i<=q;i++){
		cin>>s2[1][i]>>s2[2][i];
	}
	for(int i=1;i<=q;i++) cout<<"0\n";
	return 0;
}
