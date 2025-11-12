#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[50009];
ll sum[50099];
ll maxn[50099];
int main(){
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i] = sum[i-1]+a[i];
		//maxn[i]
		
	}
	
	ll count=0;
	if(n<=100){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ll sumnow = sum[j]-sum[i-1];
				ll maxh = 0; 
				for(int k=i;k<=j;k++){
					if(a[k]> maxh) maxh = a[k];
				}
				
				if(sumnow >2*maxh){
					cout<<sumnow<<" "<<maxh<<endl;
					
				} count++;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ll sumnow = sum[j]-sum[i-1];
				
			}
		}
	}
	cout<<count<<endl; 
	
	return 0;
}
