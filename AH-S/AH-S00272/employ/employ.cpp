#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
char s[505];
int c[505],x[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt,sum,ans=0;
	scanf("%d%d%s",&n,&m,s);
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
		x[i]=i;
	}
	do{
		cnt=sum=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'&&c[x[i]]>cnt)sum++;
			else cnt++;
			if(sum==m){
				ans=(ans+1)%mod;
				break;
			}
		}
	}
	while(next_permutation(x+1,x+n+1));
	printf("%d",ans);
	return 0;
}
