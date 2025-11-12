#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.in","w",stdout);
	int n;cin>>n;
	int a[n];
	int r;cin>>r;int cnt=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==r){
			cnt++;
			a[i]=0;
		}
	}
	int sum=0;
	for(int i=2;i<=n;i++){
		for(int j=0;j<n;j++){
			for(int k=j;k<j+i;k++){
				sum^=a[k];
				if(sum==r){
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
