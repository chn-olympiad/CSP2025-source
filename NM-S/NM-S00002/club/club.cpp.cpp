#include <iostream>
using namespace std;
int main (){
	freopen("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	long long t=0;
	scanf("%lld",&t);
	for(int i=1;i<=t;i++){
		long long n=0;
		scanf("%lld",&n);
		long long x[10]={};
		long long y[10]={};
		long long b=0;
		long long a=0;
		long long c=0;
		long long d=0;
		for(int j=1;j<=n;j++){
			a=0;
			c=0;
			d=0;
			for(int k=1;k<=3;k++){
				cin>>x[k];
				if(x[k]>a){
					d=a;
					a=x[k];
					c=k;
				//	cout<<"max:"<<a<<"\n";
					}
				}
			y[c]=y[c]+1;
			//cout<<c<<"bu men"<<"bu men ren shu "<<y[c]<<"\n";
			if(y[c]>n/2){
				b=b+d;
				}else{
				b=b+a;	
				}
			}
			if(b==2){
				b=b+2;
				}
			if(b==10){
				b=b+3;
				}
		printf("%lld",b);
		}	
		
		
	return 0;
	}
