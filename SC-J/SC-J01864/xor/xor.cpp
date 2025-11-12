#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s0=0,s1=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0) s0++;
		else s1++;
	}
	if(s1==n&&k==0) printf("%d\n",n/2);
	else if(k==1) printf("%d\n",s1);
	else{
		int sum=1;
		for(int i=1;i<=n;i++)
			if(a[i]==1&&a[i-1]==1) sum++;
			else s0+=sum/2,sum=1;
		printf("%d\n",s0);
	}
	return 0;
}