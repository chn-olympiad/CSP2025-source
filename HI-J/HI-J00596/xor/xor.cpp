#include<bits/stdc++.h>
using namespace std;
int n,k,ans,sum=0;
int a[600005];
struct pp{
	int x,y;
};
int yh(int l,int r){
	int zz=a[l];
	for(int i=l+1;i<=r;i++){
		zz=(zz^a[i]);
	}
	return zz;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(yh(j,i)==k) ans=max(ans,i-j);
		}
	}
	printf("%d",ans);
	return 0;
}

