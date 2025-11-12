#include<bits/stdc++.h>
using namespace std;
long long n,q,a;
string s[200001][3],t[200001][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++){
		cin>>t[i][1]>>t[i][2];
	}
	
	for(int i=1;i<=q;i++){
		printf("%lld\n",&a);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
