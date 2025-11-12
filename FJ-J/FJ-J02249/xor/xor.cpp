#include<bits/stdc++.h>
using namespace std;
int s[500010],a[500010],f[500010],mx[1100010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	s[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	memset(mx,0,sizeof(mx));
	mx[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=max(f[i-1],mx[s[i]^k]);
		mx[s[i]]=max(mx[s[i]],f[i]+1);
	}
	printf("%d",f[n]);
	return 0;
}
