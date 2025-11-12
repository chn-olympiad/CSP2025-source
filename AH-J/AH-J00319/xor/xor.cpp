#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int f[500005][4],a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,gg;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n;i++){
		a[i]^=a[i-1];
	}
	mp[0]=0;
	for(int i=1;i<=n;i++){
		gg=mp[a[i]^k];
		mp[a[i]]=i;
		if((gg!=0)||(a[i]==k)){
			f[i][1]=max(f[gg][0],f[gg][1])+1;
			f[i][0]=max(f[i-1][0],f[i-1][1]);
		}else{
			f[i][1]=0;
			f[i][0]=max(f[i-1][0],f[i-1][1]);
		}
	}
	printf("%d",max(f[n][0],f[n][1]));
	return 0;
}
