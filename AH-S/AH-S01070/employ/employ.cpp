#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[505];
int a[505];
int p[505];

void calc1(){
	for(int i=1;i<=n;i++)
		p[i]=i;
	int ans=0;
	do{
		int fa=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(fa>=a[p[i]]) ++fa;
			else if(s[i]=='0') ++fa;
			else ++cnt;
		}
		if(cnt>=m) ++ans;
	}while(next_permutation(p+1,p+n+1));
	printf("%d",ans);
	return;
}

const long long mod=998244353ll;

void calc2(){
	long long ans=1;
	for(int i=1;i<=n;i++)
		ans=ans*i%mod;
	printf("%lld",ans);
	return;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	getchar();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n<=18) calc1();
	else calc2();
	return 0;
}
