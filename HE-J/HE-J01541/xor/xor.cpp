#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,sum=0;
	cin>>n>>k;
	int m[n+1];
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	for(int i=1;i<=n;i++){
		if(m[i]==k)sum++;
		long long j=i+1,x=m[i];
		while(j<=n){
			int y=m[j],ls1=0,q=1;
			while(x|y){
				if(x%2!=y%2)ls1+=q;
				x/=2;
				y/=2;
				q*=2;
			}
			x=ls1;
			if(x==k){
				sum++;
				i=j;
				break;
			}
			j++;
		}
	}
	cout<<sum;
	return 0;
} 
