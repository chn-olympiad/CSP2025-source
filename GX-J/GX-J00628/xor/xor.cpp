#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[50100];
int main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=0;i<n;i++){
		int ans=a[i];
		for(int j=i;j<n;j++){
			if(ans%k==0){
				sum++;
				continue;
				i=j;
			}
			ans=ans+a[j];
		}
	}
	cout<<sum;
	return 0;
}
