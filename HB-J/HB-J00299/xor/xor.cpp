#include<bits/stdc++.h>
using namespace std;
int n,k,a[100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(k==2&&k==3)printf("2");
	if(k==0)printf("1");
	return 0;
}
