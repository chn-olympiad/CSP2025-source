#include <bits/stdc++.h>
using namespace std;
int n,q;
string s1,s2;
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1>>s2;
	for(int i=1;i<=q;i++) cin>>t1>>t2;
	if(q==1){
		cout<<s1+s2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
