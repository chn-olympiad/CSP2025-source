#include<bits/stdc++.h>
using namespace std;

long n,k;
long a[500005],b[500005],sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	long l=1,r=1;//×óÓÒ±ß½ç 
	for(int i=1;i<=n,l<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		for(int j=l;j<=n;j++){	
			if(j!=l){
				b[j]=b[j-1]^b[j];	
			}					
			r=i;
			if(b[j]==k){
				sum++;
				r=j; 
				break;
			}
		}
		l=r+1;
	}
	cout<<sum;
	return 0;
}
