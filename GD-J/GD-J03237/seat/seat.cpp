#include<bits/stdc++.h>
using namespace std;
int n,m,num,a[105],d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	num=n*m;
	for(int i=1;i<=num;i++){
		int x;
		scanf("%d",&x);
		if(i==1)d=x;
		a[x]++;
	}
	for(int i=100;i>=1;i--)a[i]+=a[i+1];
	d=a[d];
	num=1;
	int i=1,j=0;
	while(num<=d){
		if(i%2){
			j++;
			if(j>n){
				j=n;
				i++;
			}
		}else{
			j--;
			if(j<1){
				j=1;
				i++;
			}
		}
		num++;
	}
	printf("%d %d\n",i,j);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
