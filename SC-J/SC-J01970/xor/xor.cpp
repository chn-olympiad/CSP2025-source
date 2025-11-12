#include<bits/stdc++.h>
using namespace std;
const int U=2e6,N=5e5+5,inf=0x3f3f3f3f;
int n,k,lst[U],f[N],a[N],s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	memset(lst,0x3f,sizeof lst);
	lst[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		s[i]=s[i-1]^a[i];
		int tmp=s[i]^k;
		f[i]=f[i-1];
		if(lst[tmp]<inf){
			f[i]=max(f[i],f[lst[tmp]]+1);
		}
		lst[s[i]]=i;
	}
	printf("%d\n",f[n]);
	return 0;
}
/*
本来以为会很难。。。
10min解决了。。。
*/