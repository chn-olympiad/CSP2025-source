#include<bits/stdc++.h>
using namespace std;
int n,m,num,x,ans1,ans2,num_;
void init(){
	num=0;
	x=1;
	return ;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	init();
	scanf("%d%d",&n,&m);
	scanf("%d",&num_);
	for(int i=1;i<n*m;i++){
		scanf("%d",&num);
		if(num>num_){
			x++;
		}
	}
	if(x%n==0){
		ans2=x/n;
	}else{
		ans2=x/n+1;
	}
	ans1=x%n;
	if(ans1==0){
		ans1=n;
	}
	if(ans2%2==0){
		ans1=n-ans1+1;
	}
	printf("%d %d\n",ans2,ans1);
	return 0;
}
