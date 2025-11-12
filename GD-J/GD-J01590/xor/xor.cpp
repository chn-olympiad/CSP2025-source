#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,b[500005],o,c[500005],d[500005],k,sum;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),b[i]=a[i];
		if(a[i]==m) sum++,c[++o]=i,d[o]=i,k++;
	}
	for(int len=1;len+k<n;len++){
		for(int i=1;i+len<=n;i++){
			if(k+len>=n) break;
			bool f=0;
			for(int j=1;j<=o;j++){
				if(c[j]>i+len||d[j]<i)
					continue;
				f=1;
				break;
			}
			if(f) continue;
			b[i]=b[i]^a[i+len];
			if(b[i]==m)
				sum++,c[++o]=i,d[o]=i+len,k+=len;
		}
	}
	printf("%d",sum);
	return 0;
} 
