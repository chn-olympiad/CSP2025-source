#include<bits/stdc++.h> 

using namespace std;

long long a[10001],n,m;

int main(){
	
	freopen("seat.in","r",stdin);
	
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	
	for(long long i=1;i<=n*m;i++){
		
		cin>>a[i];
	}
	
	long long s=a[1];
	
	sort(a+1,a+n*m+1);
	
	long long q=0;
	
	for(long long j=1;j<=m;j++){
		
		
		
		if(j%2==1){
			
			for(long long i=1;i<=n;i++){
			
				q++;
			
				if(a[q]==s){
					
					cout<<i<<" "<<j;
					
					return 0;
				}
				
				
			}
		}
		else{
			
			q+=n-1;
			
			for(long long i=1;i<=n;i++){
				
				q++;
				
				if(a[q]==s){
					
					cout<<i<<" "<<j;
					
					return 0;
				}
				
				
			}
		}
	}
	
	
	
	fclose(stdin);
	
	fclose(stdout);
	
	return 0;
}
