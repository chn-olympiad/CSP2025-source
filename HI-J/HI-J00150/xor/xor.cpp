#include<bits/stdc++.h>
using namespace std;

int n,k;
int sum=0,sum1;
int ans=0,cot=0;
int a[500020];
void x(int l){
	bool ja=0;
	
	if(l<n){
		for(int i=l;i<n;i++){
			sum=sum^a[i];
			//cout<<a[i]<<" ";
			if(sum==k){
				ans++;
				ja=1;
				sum1=sum;
				sum=0;

			}
			x(i+1);
			cot=max(ans,cot);
			if(ja==1){
				ja=0;
				ans--;
				sum=sum1;
			}
		
			sum=sum^a[i];
			
		}
		//cout<<ans<<endl;
		
	}
	
	
	
	
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//cout<<((38^38)^38);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
		x(0);
		//ans=0;
	
	cout<<cot;
	return 0;
}
