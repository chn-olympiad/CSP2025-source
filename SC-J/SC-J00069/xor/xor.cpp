#include<bits/stdc++.h>
using namespace std;
int a[500010],n,b[500010],t,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	b[0]=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=(b[i-1]^a[i]);
	}
	int P=0;
	for(int R=1;R<=n;R++){
		for(int L=R-1;L>=P;L--){
			if((b[R]^b[L])==k){
				t++;
				P=R;
				continue;
			}
		}
	}	
	printf("%d",t);
	return 0;
}