#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	std::cin>>n>>m;
	long long a[n*m+2];
	for(int i=1;i<=n*m;i++) std::cin>>a[i];
	long long r=a[1];
	for(int i=1;i<n*m;i++)
		for(int j=1;j<n*m;j++)
			if(a[j]<a[j+1]) std::swap(a[j],a[j+1]);
	long long lie;
	for(int i=1;i<=n*m;i++){
	    if(a[i]==r){
			if(i==n&&i/n%2!=0&&i/n!=1){
			    std::cout<<i/n<<" "<<"1";
			    return 0;
		    }
		    if(i==n&&i/n%2==0||i/n==1&&i==n){
		    	std::cout<<i/2<<" "<<n;
		    	return 0;
			}
	        lie=i/n+1;
		    if(lie%2!=0){
			    if(i<n){
			    	std::cout<<lie<<" "<<i;
			    	return 0;
				}
				else{
					std::cout<<lie<<" "<<i-n*(lie-1);
					return 0;
				}
		    }
		    else if(lie%2==0){
		    	std::cout<<lie<<" "<<n-(i%n-1);
		    	return 0;
			}
		}
	}		
		
	return 0;
}

