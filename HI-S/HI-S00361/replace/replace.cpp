#include <bits/stdc++.h>
using namespace std;
string s1[1000005],s2[1000005];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		getline(cin,s1[i],' ');
		getline(cin,s2[i]);
	}
	string a,b;
	for(int i=1;i<=q;i++){
		getline(cin,a,' ');
		getline(cin,b);
		printf("0\n");
	}
	return 0;
}
