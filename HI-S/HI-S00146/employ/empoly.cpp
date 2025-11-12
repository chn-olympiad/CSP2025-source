#include<bits/stdc++.h>
using namespace std;
int n,m,c[501];
long long sum=1; 
string k;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",&k);
	for(int i=0;i<n;i++) scanf("%d",&c[i]);
	for(int i=n;i>1;i--) sum=sum*i%998244353;
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
