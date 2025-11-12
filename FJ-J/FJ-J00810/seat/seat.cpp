#include<bits/stdc++.h>
using namespace std;
int m,ans_n,ans_m,x;
int nums[105];
double n;
int main(){

	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lf%d",&n,&m);
	for(int i=0;i<n*m;i++){
		scanf("%d",&nums[i]);
		if(i!=0 and nums[i]>nums[0]){
			x++;
		}
	} 
	ans_m=ceil((x+1)/n);
	if((x+1)%int(n)==0){
		ans_n=n;
	}
	else{
		ans_n=(x+1)%int(n);
	}
	if(ans_m%2==0){
		ans_n=n-ans_n+1;
	}
	printf("%d %d",ans_m,ans_n);

	return 0;
}

