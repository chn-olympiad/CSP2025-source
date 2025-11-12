#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(k==0){
		int cnt0=0;
		for(int i=0;i<n;i++){
			if(a[i]==0){
				cnt0++;
			}
			else if(a[i]==1&&a[i+1]==1){
				cnt0++;
				a[i+1]=-1;
			}
		}
		printf("%d\n",cnt0);
	}
	else if(k==1){
		int cnt1=0;
		for(int i=0;i<n;i++){
			if(a[i]==1){
				cnt1++;
			}
		}
		printf("%d\n",cnt1);
	}
	return 0;
}
