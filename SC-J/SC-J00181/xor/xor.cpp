#include<iostream>
using namespace std;
const int N=5e5+10;
int a[N],f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k; 
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int fl=1,fl2=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=1)fl=0;
		if(a[i]!=1&&a[i]!=0)fl2=0;
	}
	if(fl){
		if(k==1){
			printf("%d",n);
		}else if(k==0){
			printf("%d",n/2);
		}else printf("0");
	}
	else if(fl2){
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				cnt1++;
				if(i+1<=n&&a[i+1]==1&&f[i]==0&&f[i+1]==0){
					cnt0++;
					f[i+1]=f[i]=1;
				}
			}
			else cnt0++;
		}
		if(k==1)printf("%d",cnt1);
		else printf("%d",cnt0);
	}
	return 0;
}