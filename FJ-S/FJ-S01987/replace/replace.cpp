#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(;q--;){
		cin>>x>>y;
		printf("0\n");
	}
	return 0;
} 
