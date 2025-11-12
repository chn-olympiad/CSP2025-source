#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[511];
int a[511];
int p=0;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	bool b=false;
	for(int i=1;i<=n;i++)
		if(s[i]=='1')
			b=true;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]==0)
			p+=1;
	int ans=1;
	for(int i=2;i<=n-p;i++)
		ans*=i,ans%=998244353;
	
	if(b)
		printf("%d",ans);
	else
		printf("0");
	return 0;
}
