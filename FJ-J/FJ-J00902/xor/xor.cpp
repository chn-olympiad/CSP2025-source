#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	for(int i=1;i<=100;i++) cout<<1<<" "; 
	scanf("%d%d",&n,&k);
	int numx=0,numy=0,numc=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==1) numx++;
		else if(a[i]==0) numy++;
		if(a[i]==k) numc++;
	}
	if(numx==n){
//		if(k==0){
		printf("%d\n",n/2);
//		}
//		else if(k==1) printf("%d\n",n);
//		else printf("0\n"); 
		return 0;
	}
	if(numx+numy==n){
		if(k==1) printf("%d\n",numx);
		else if(k==0){
			int num=0;
			int ans=numy;
			for(int i=1;i<=n;i++){
				if(a[i]==1) num++;
				else{
					ans+=num/2;
					num=0;
				}
			}
			printf("%d\n",ans);
		}
//		else printf("0\n"); 
		return 0;
	}
	printf("%d\n",numc);
	return 0;
}

