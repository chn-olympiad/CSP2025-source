#include<bits/stdc++.h>
using namespace std;
int a[5010],n,sum;
int check(int l){
	int ma=0;
	for(int i=l;i<=l+2;i++){
		if(a[i]>ma){
			ma=a[i];
		}
	}
	if(a[l]+a[l+1]+a[l+2]>ma*2){
		sum++;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n-2;i++){
		check(i);
	}
	printf("%d",sum);
	return 0;
}

