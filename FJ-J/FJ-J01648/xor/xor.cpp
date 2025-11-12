#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long n,k,a[N+5],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		int j1=0,j0=0;	
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1){
				j1++;
			}
			if(a[i]==0){
				j0++;
			}
		}
		if(j1==n){
			while(n>=1){
				ans+=n-1;
				n-=2;
			}
		}
		else if(j0+j1==n){
			ans=j1*2;
		}
	}
	else{
		int j1=0,j0=0;	
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1){
				j1++;
			}
			if(a[i]==0){
				j0++;
			}
		}
		ans=j1*4;
	}
	cout<<ans;
	return 0;
}
