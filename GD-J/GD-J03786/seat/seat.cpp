#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int a[maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}	
	int xiaor=a[0];
	sort(a,a+m*n);
	for(int i=0;i<n*m;i++){
		if(a[i]==xiaor){
			xiaor=n*m-i;
			break;
		}
	}
	int y=(xiaor-1)/n+1,x;
	if(y%2==1){
		x=xiaor%n;
		}
	else{
		if(xiaor%n==0)
			x=1;
		else
			x=n-xiaor%n+1;
	} 
	printf("%d %d",y,x);
	return 0;
}
