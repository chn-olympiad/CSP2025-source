#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d,%d",&n,&k);
	int a[n];
	int b[n];
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++){
		scanf("%d",a[i]);
	}
	int num=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			num++;
			a[i]=1;
		}
		else{
			int sum=0,x=i;
			bool f=true;
			while(f){
				sum=sum^a[x];
				x++;
				if(b[x]==1){
					sum=sum^a[x];
					f=false;
					if(sum==k){
						num++;
					}
				}
			} 
		}
	}
	printf("%d",num);
	return 0;
}
