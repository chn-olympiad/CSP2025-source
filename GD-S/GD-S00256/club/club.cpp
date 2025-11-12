#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,out=0;
	cin>>t;
	for(int i=0;i<t;i++){
		long long n=0,a[50002]={},b[50002]={},c[50002]={},in1,in2,in3,c1=0,c2=0,c3=0;
		out=0;
		cin>>n;
		int sum=n/2;
		for(int j=0;j<n;j++){
			cin>>in1>>in2>>in3;
			if(in1>in2&&in1>in3){
				if(c1<sum){
					a[c1]=in1;
					sort(a,a+c1);
					c1++;
					
				}
				else{
					if(in1>a[c1-1]){
						in1=a[c1-1]; 
						a[c1-1]=in1;
						sort(a,a+c1);
						
					}
					else{
						in1=0;
					}
				}
				
			}
			if(in1<in2&&in2>in3){
				if(c2<sum){
					b[c2]=in2;
					sort(b,b+c2);
					c2++;
					
				}
				else{
					if(in2>b[c2-1]){
						in2=b[c2-1]; 
						b[c2-1]=in2;
						sort(b,b+c2);
					
					}
					else{
						in2=0;
					}
				}
			}
			if(in3>in2&&in1<in3){
				if(c3<sum){
					c[c3]=in3;
					sort(c,c+c3);
					c3++;
					
				}
				else{
					if(in3>c[c3-1]){
						in3=c[c3-1]; 
						c[c3-1]=in3;
						sort(c,c+c3);
						
					}
					else{
						in3=0;
					}
				}
			}
			if(in1==in2&&in1==in3){
				out+=in1;
			}
		}
		for(int j=0;j<sum;j++){
			out+=a[j];
			out+=b[j];
			out+=c[j];
		}
		cout<<out<<"\n";
	}
	return 0;
}

