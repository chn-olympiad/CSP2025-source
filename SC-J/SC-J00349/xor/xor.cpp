#include<bits/stdc++.h>
const int N=5*1e5+5;
int n,k,a[N],f[N];
std::map<int,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]^=a[i-1];
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(mp[a[i]])f[i]=std::max(f[i],f[mp[a[i]]]+1);
		if(a[i]==k)f[i]=std::max(f[i],1);
		mp[a[i]^k]=i;
//		printf("		%d\n",f[i]);
	}
	printf("%d",f[n]);
}