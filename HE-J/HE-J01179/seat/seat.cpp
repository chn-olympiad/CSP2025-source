#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    
	long long a[n*m];
	for(int i =0;i<n*m;i++)cin>>a[i];
	int s=a[0];
	sort(a,a+n*m);
	int j=1;
	int k=1;
	int t=1;
	for(int i =n*m-1;i>-1;i--){
		if(a[i]==s){
			if(j%i==1){			
				cout<<j<<' '<<k;
			}else{
				cout<<j<<' '<<n-k+1;
			}
			return 0;
		}	
		k++;		
		if(k==n+1){
			k=j;
			j++;
		}
		
	}
	return 0;
}
