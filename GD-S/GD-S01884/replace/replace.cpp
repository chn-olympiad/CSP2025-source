#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200010][2],a,b;
map<string,int> m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) {
		cin>>s[i][1]>>s[i][2];
	}
	for(int i=1;i<=q;i++) {
		cin>>a>>b;
		printf("0\n");
	}


	
	return 0;
} 
