#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m,p[N],tot;
string s;
int calc(int tem){
	int res=1;
	for (int i=tem;i>=1;i--)
	res=res*i%mod;
	return res%mod;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	tot=n;
	cin>>s;
	for (int i=1;i<=n;i++) {
		scanf("%d",&p[i]);
		if (p[i]==0) tot--;
	}
	if (tot<m) printf("0\n");
	else printf("%d\n",calc(n));
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
