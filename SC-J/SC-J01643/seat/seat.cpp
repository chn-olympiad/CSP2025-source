#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,b,a[100001];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n*m);

	for(int i=1;i<=n*m;i++){
		int k=i;
		if(a[i]==b){
			cout<<n-((k+1)/n-1)<<" ";
			if(m%2==0){
	      		if(((i-1)/n+1)%2==0){
					if(i%n!=0){
						cout<<n-(i%n)+1;
					}
					else{
						cout<<1;
					}
				}else
				{
				
					if(i%n!=0){
						cout<<i%n;
					}
					else{
						cout<<n;
					}
					
				}
			}
				else{
					if(((i-1)/n+1)%2!=0){
					if(i%n!=0){
						cout<<n-(i%n)+1;
					}
					else{
						cout<<1;
					}
				}else
				{
				
					if(i%n!=0){
						cout<<i%n;
					}
					else{
						cout<<n;
					}
					
				}
					
				}
			break;
			
		}
	}
	
	return 0;
}
