#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int n,k,a[MAXN],p[MAXN],f[MAXN]={0},ans;
int main(){
	int i,j;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		p[i]=p[i-1]^a[i];
	}
	for(i=1;i<=n;i++){
		f[i]=f[i-1];
		for(j=0;j<i;j++){
			if((p[i]^p[j])!=k)continue;
			f[i]=max(f[i],f[j]+1);
		}
	}
	cout<<f[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
