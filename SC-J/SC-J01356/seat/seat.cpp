#include<bits/stdc++.h> 
using namespace std;
int n,m,p,s=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<n*m;i++){
		int x;scanf("%d",&x);
		if(x>p)	s++;
	}
	int c=(s+m-1)/m;
	printf("%d ",c);
	if(c%2==0){
		if(s%m==0)	printf("1");
		else		printf("%d",m-(s%m)+1);
	}
	else{
		if(s%m==0)	printf("%d",m);
		else		printf("%d",s%m);
	}
	return 0;
}