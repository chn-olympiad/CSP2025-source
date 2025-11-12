#include<bits/stdc++.h>
using namespace std;
int a[102];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t,n1,m1;
	scanf("%d%d",&n,&m);
	int j=1,x=1;
	while(cin>>a[j]){j++;}
	j--;
	int r;
	r=a[1];
	sort(a+1,a+j+1,cmp);
	while(a[x]!=r){x++;}
	if(x<n){
		printf("1 %d",x);
		return 0;
	}
	t=x%n;
	if((x/n)%2){
		n1=n-t+1;
		if(t==0) n1--;
	}
	else{
		n1=t;
		if(t==0){
			n1++;
		}
	}
	m1=x/n;
	if(t!=0){
		m1++;
	}
	printf("%d %d",m1,n1);
	return 0;
} 
