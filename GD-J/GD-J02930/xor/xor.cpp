#include<bits/stdc++.h>
using namespace std;
long long a[600009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	long long sum=0;
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=n-i-1;j++){
			long long num=a[j];
			for(int z=j+1;z<=j+i;z++){
				num=num^a[z];
			}
			if(num==k){
				sum++;
				for(int z=j;z<=j+i;z++){
					a[z]=-1000;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}

