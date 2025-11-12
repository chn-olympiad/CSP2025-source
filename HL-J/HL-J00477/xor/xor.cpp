#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,ans=0,xb=-1;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		
		int z=a[++xb];
		if(xb==n){
			break;
		}
		if(z==k){
			ans++;
			continue;
		} 
		for(int j=xb+1;j<n;j++){
			z=z^a[j];
			if(z==k){
				ans++;
				xb=j;
				break;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
