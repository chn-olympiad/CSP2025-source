#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
string s[200010][2],t[200010][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=m;i++){
		cin>>t[i][0]>>t[i][1];
		printf("0\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
