#include<bits/stdc++.h>
using namespace std;
long long int n,k;
long long int a[10000000],b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			b+=1;
			a[i]=-1;
		}
	}
	long long int c=0;
	for(long long int i=1;i<=n;i++){
		if(a[i]!=-1){
			c=(c^a[i]);
			if(c==k){
				b+=1;
				c=0;
				
			}
		}else{
			c=0;
		}
	}
	cout<<b;
	return 0;
} 
