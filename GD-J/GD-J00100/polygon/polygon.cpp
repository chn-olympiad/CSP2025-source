#include<bits/stdc++.h>
using namespace std;
int n,a[5010],sor[5010]={0};
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}	
	for(int i=1;i<=n;i++){
		sor[a[i]] += 1; 
	}
	int idx=1,s_num=0;
	for(int i=1;i<=5001;i++){
		while(sor[i]){
			if(s_num == n)	break;
			a[idx] = i;
			sor[i]--;
			s_num++;
			idx++;
		}
	}
	if(n<=2){
		printf("0");
	}else if(n==3){
		if(a[1]+a[2]+a[3] > a[3]*2){
			printf("1");
		}else{
			printf("0");
		}
	}else{
		int sum=0;
		for(int i=1;i<=n;i++){
			sum += a[i];
		}
		if(sum>=a[n]){
			printf("0");
		}
	}
	return 0;
}
