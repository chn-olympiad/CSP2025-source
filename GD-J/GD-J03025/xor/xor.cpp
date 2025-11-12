#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int r=0;r<n;r++){
		for(int l=r;l<n;l++){
			int ans=a[r];
			for(int z=r+1;z<=l;z++){
				ans^=a[z];
			}
			if(ans==k){
				sum++;
				r=l;
			}
		}
	}
	cout<<sum;
	return 0;
} 
