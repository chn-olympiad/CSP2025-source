#include<bits/stdc++.h>
using namespace std;
int n,k,l,y,a[500005];bool pd;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) pd=1;
		if(a[i]==0) l++;
		if(a[i]==1) y++;
	}
	if(!pd){
		printf("%d",n/2);
		return 0;
	}
	else{
		if(k==0){
			printf("%d",l+y/2);
			return 0;
		}
		else{
			printf("%d",y);
			return 0;
		}
	}
	return 0;
}
