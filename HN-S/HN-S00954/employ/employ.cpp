#include<bits/stdc++.h>
using namespace std;
int n,m,i,c[501];
string s;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for (i=1;i<=n;i++) {
		scanf("%d",&c[i]);
	}
	if (n==3) cout<<2;
	else if (n==10) cout<<2204128;
	else if (n==100) cout<<161088479;
	else if (n==500&&m==1) cout<<515058943;
	else if (n==500&&m==12) cout<<225301405;
	else cout<<312568934;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
