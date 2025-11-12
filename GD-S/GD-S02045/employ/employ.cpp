#include <bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int st;
}g[505];
int n,m;
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&g[i].a);
		g[i].st=i-1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
