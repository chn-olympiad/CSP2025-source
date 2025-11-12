#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long mine=n+1,sum=0;
	for(int i=1;i<=n;i++){
		if(i>=mine){
			sum++;
			i=mine+1;
			mine=n+1;
		}
		s=0;
		for(int j=i;j<=n;j++){
		    s=(s^a[j]);
			if(j>=mine)break;
			if(s==k){
				if(j<mine)mine=j;
				break;
			}
		}
	}
	cout<<sum;
} 
