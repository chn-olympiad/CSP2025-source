#include<bits/stdc++.h>
using namespace std;
int a[125],n,m,o,ct,sum,po=0,pl=1,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	o=n*m;
	for(int i=1;i<=o;i++){
		scanf("%d",&a[i]);
	}
ct=a[1];
sort(a,a+o+1);
for(int i=1;i<=o;i++){
	if(a[i]==ct){
		sum=o-i+1;
		k=sum;
		for(int p=1;p<=sum;p++){
			if(po==n&&pl%2!=0){
				pl++;
			}
			else if(po==1&&pl%2==0){
				pl++;
			}
			else if(pl%2!=0){
				po++;
			}
			else if(pl%2==0){
				po--;
			}
		}
		printf("%d %d",pl,po);
		return 0; 
	}
}

return 0;
} 
