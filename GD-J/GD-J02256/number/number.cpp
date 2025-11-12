#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000005];
ll n,m,a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]>='0'&&s[i]<='9')a[++m]=s[i]-'0';
	sort(a+1,a+m+1);
	for(int i=m;i>0;i--)printf("%lld",a[i]);
	return 0;
}
