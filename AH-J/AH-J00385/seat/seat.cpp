#include<bits/stdc++.h>
using namespace std;
int n,m,a[109],tp,x;
bool t[109];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	tp=n*m;
	scanf("%d",&a[1]);
	x=a[1];
	t[a[1]]=1;
	for(int i=2;i<=tp;i++){
		scanf("%d",&a[i]);
		t[a[i]]=1;
	}
	int sum=0;
	for(int i=100;i>=x;i--){
		sum+=t[i];
	}
	tp=(sum-1)/n;
	sum=sum-tp*n;
	tp++;
	if(tp&1){
		printf("%d %d",tp,sum);
	}
	else{
		printf("%d %d",tp,n-sum+1);
	}
	return 0;
}
