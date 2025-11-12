#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=(1<<20)+10;
int n,k,a[N],s[N],f[N],mx[M];
int main(){
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<M;i++)mx[i]=-1e9;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),s[i]=s[i-1]^a[i];
		f[i]=max(f[i-1],mx[s[i]^k]+1),mx[s[i]]=max(mx[s[i]],f[i]);
//		printf(":%d %d\n",f[i],a[i]);
	}
	printf("%d\n",f[n]);
	fclose(stdin),fclose(stdout);
	return 0;
}