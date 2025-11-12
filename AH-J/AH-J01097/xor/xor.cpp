#include<bits/stdc++.h>
using namespace std;
const int INF=5e5+10;
int n,k;
int a[INF];
bool flag[INF];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	int d=1;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(a[i]!=1) d=-1;
	}
	if(d==1&&k==0){
		 printf("%d",n/2);
		 return 0;
	}
	if(k==1){
		int sum1=0;
		for(int i=2; i<=n; i++){
			if(a[i]!=a[i-1]){
				sum1++;
				flag[i]=flag[i-1]=true;
				i++;
			}
		}
		for(int i=1; i<=n; i++)
			if(flag[i]==false&&a[i]==1)
				sum1++;
		printf("%d",sum1);
		return 0;
	}
	else if(k==0){
		int sum2=0;
		for(int i=2; i<=n; i++){
			if(a[i]==a[i-1]){
				sum2++;
				flag[i]=flag[i-1]=true;
				i++;
			}
		}
		for(int i=1; i<=n; i++)
			if(flag[i]==false&&a[i]==0)
				sum2++;
		printf("%d",sum2);
		return 0;
	}
	return 0;
}
