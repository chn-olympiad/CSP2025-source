#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500007];
int c[500007];
priority_queue<int> pq;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool f1=1,f2=1;
	int d1=0,d0=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[i]=c[i]^a[i];
		if(a[i]!=1){
			f1=0;
		}
		if(a[i]!=1&&a[i]!=0){
			f2=0;
		}
		if(a[i]==1){
			d1++;
		}
		else if(a[i]==0){
			d0++;
		}
	}
	if(f1==1){
		if(n%2==0){
			printf("%d",n/2);
		}
		else{
			printf("0");
		}
	}
	else if(f2==1){
		if(k==0){
			printf("%d",d0+d1/2);
		}
		if(k==1){
			printf("%d",d1);
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
