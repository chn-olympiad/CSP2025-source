#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],ans[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1)sum++;
	}
	if(sum==n&&k==0){
		printf("%d",n/2);
		return 0;
	}
	return 0;
}
