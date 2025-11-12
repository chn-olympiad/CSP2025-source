#include<bits/stdc++.h> 

using namespace std;

long long n,k;

long long a[1000001];

int main(){
	
	freopen("xor.in","r",stdin);
	
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	
	for(long long i=1;i<=n;i++){
		
		cin>>a[i];
		
		if(i>=2) a[i]+=a[i] xor a[i-1];
	}
	
	long long cnt=0,mmax=1;
	
	for(long long i=n;i>=1;i--){
		
		for(long long j=0;j<i;j++){
			
			if(a[i]-a[j]==k&&j+1>=mmax){
				
				cnt++;
				
				mmax=j+1;
			}
		}
	}
	
	cout<<cnt;
	
	fclose(stdin);
	
	fclose(stdout);
	
	return 0;
}
