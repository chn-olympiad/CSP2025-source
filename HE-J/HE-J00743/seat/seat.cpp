#include<bits/stdc++.h>
using namespace std;
int n,m,s,k,num[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	s=n*m;
	num[0]=k;
	for(int i=1;i<s;i++){
		scanf("%d",&num[i]);
	}
	sort(num,num+s);
	for(int i=0;i<s;i++){
		if(num[i]==k){
			k=s-i;
			break;
		}
	}
	int c=k/(n*2);
	int d=k%(n*2);
	if(d==0){
		printf("%d %d",c*2,1);
	}
	else{
		if(d>n){
			printf("%d %d",c*2+2,n*2-d+1);
		}
		else{
			printf("%d %d",c*2+1,d);
		}
	}
	return 0;
}
