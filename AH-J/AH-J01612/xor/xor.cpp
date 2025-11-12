#include<bits/stdc++.h>
using namespace std;
int nor[500005];
int f[500005];
int nxor(int a,int b){
	int c[21],d=0,i;
	for(i=1;i<=20;i++){
		if(a%2==0)
			c[i]=b%2;
		else
			c[i]=(1-b%2);
		a/=2;
		b/=2;
	}
	for(i=20;i>=1;i--)
		d=d*2+c[i];
	return d;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,i,j,k,l,ans,s;
	scanf("%d %d",&n,&k);
	ans=0;
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++)
		scanf("%d",&nor[i]);
	for(i=1;i<=n;i++)
		f[i]=f[i-1]^nor[i];
	l=0;
	for(i=1;i<=n;i++){
		if(nor[i]==k){
			l=i;
			ans++;
			continue;
		}
		else{
			for(j=l;j<=i-1;j++){
				s=nxor(f[i],f[j]);
				if(s==k){
					ans++;
					l=i;
					break;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
