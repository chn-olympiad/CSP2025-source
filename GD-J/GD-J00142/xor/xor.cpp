#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f[500005],l[500005];
map<int,int> ma;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	}
	ma[0]=0;
	for(int i=1;i<=n;i++){
		if(ma.find(a[i]^k)==ma.end()){
			l[i]=-1;
		}
		else{
			l[i]=ma[a[i]^k]+1;
		}
		if(ma.find(a[i])==ma.end()) ma[a[i]]=i;
		else ma[a[i]]=max(ma[a[i]],i);
	}
	for(int i=1;i<=n;i++){
		if(l[i]!=-1) f[i]=max(f[i-1],f[l[i]-1]+1);
		else f[i]=f[i-1];
	}
	printf("%d",f[n]);
	return 0;
}
