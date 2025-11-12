#include<bits/stdc++.h>
using namespace std;
int n,m;
int num=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	int input;
	int rr;
	scanf("%d",&rr);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&input);
		if(input>rr) num++;
	}
	int c=ceil((double)num/(double)m);
	int r;
	if(c%2==1){
		if(num%n==0) r=n;
		else r=num%n;
	}else{
		if(num%n==0) r=1;
		else r=n-num%n+1;
	}
	printf("%d %d",c,r);
	return 0;
}

