#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long m(0),n(0);
	scanf("%ld %ld",&m,&n);
	long len=m*n;
	vector<int> x(len+5);
	vector<int> num(150);
	
	long xr=0,xx(0),yy(0);
	for(long i=1;i<=len;i++){
		long t=0;
		scanf("%ld",&t);
		if(i==1){
			xr=t;	
		}
		
		num[t]++;
	}
	long ind=1;
	for(long j=100;j>=0;j--){
		for(long i=1;i<=num[j];i++){
			x[ind]=j;
			ind++;	
	}
	}
	
	bool fl=0;
	for(long i=1;i<=n;i++){
		for(long j=1;j<=m;j++){
			if(j%2!=0){
				long t=(j-1)*n+i;
				
				//cout<<t<<" ";
			
				if(x[t]==xr){
					xx=i;
					yy=j;
					fl=1;
					break;
				}
			}else{
				
				long k=(2*j)-(i-1);
				if(x[k]==xr){
					xx=i;
					yy=j;
					fl=1;
					break;
					}
			
			}	
		
		}
		if(fl==1){
			break;
		}
	}

	printf("%d %d",xx,yy);
	return 0;
}

