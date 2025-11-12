#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0;
bool b[500005];
int yh(int l,int r){
	int x=a[l];
	for(int i=l+1;i<=r;i++) x^=i;
	return x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d\n",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d ",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(yh(i,j)==k) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
