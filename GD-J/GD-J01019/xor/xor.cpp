#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,f[N],a[N],b[N],c[N],k;
int lst[N],p;
int turn(int x){
	return lower_bound(b,b+1+n,x)-b;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	b[0]=c[0]=k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
		b[i]=c[i]=a[i]^k;
	}
	sort(b,b+1+n);
	memset(lst,-1,sizeof(lst));
	for(int i=1;i<=n;i++){
		lst[turn(c[i-1])]=i-1;
		p=turn(a[i]);
		f[i]=f[i-1];
		if(b[p]==a[i]&&lst[p]!=-1)f[i]=max(f[i],f[lst[p]]+1);
	}
	printf("%d",f[n]);
	return 0;
}

