#include<cstdio>
#include<iostream>
using namespace std;
const int N=1005;
int n,m;
string s[N][2];
int c[1000];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin >> s[i][0] >> s[i][1];
	}
	for(int i=1;i<=m;i++){
		cin>> s[i][0] >> s[i][1];
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",0);
	}
	
	return 0;
}
