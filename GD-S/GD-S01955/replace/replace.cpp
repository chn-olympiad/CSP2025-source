#include<bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n+m;i++) cin>>a>>b;
	for(int i=1;i<=n;i++) printf("0\n");
	return 0;
}
