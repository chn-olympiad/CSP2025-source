#include <bits/stdc++.h>
using namespace std;
long long n,x,c;
long long maxs;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>x;
	int a[n+10];
	int b[n+10];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n;i++){
		maxs=1;
		for(int j = 0;j<n;j++){
			for(int k=0;k<=j;k++){
				if(a[j]==b[k]){
					continue;
				}
			}
			if(maxs<a[j]){
				maxs=a[j];
			}
		}
		b[i]=maxs;
	}
	for(int l=0;l<n;l++){
		if(b[l]==a[0]){
			c=l;
		}
	}
	if(c<=n){
	cout<<1<<n;
    }else{
    	if((c/n)%2==0){
    		if(c%n==0){
    			cout<<c/n<<" "<<1;
			}else{
				cout<<c/n+1<<" "<<c%n+1;
			}
		}else{
			if(c%n==0){
				cout<<c/n<<" "<<n;
			}else{
				cout<<c/n+1<<" "<<n-c%n+1;
			} 
		} 
	}
	return 0;
}
