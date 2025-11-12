#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,t=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int h=0;
		for(int j=i;j<=n;j++){
			h^=a[j];
			if(h==k){
				t++;
			}
		}
	}
	printf("%d",t);
	return 0;
}
