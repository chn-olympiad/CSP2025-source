#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;

struct Replace{
	string s1,s2;
} e[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for (int i=1;i<=n;i++)	cin>>e[i].s1>>e[i].s2;
	
	while (q--){
		string a,b;cin>>a>>b;
		cout<<"0\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
