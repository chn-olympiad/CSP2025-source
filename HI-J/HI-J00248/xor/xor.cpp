#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) sum++;
	}
	if(k==1) ans=sum;
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==1&&i<n&&a[i+1]==1) ans++,i++;
			if(a[i]==0) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}

