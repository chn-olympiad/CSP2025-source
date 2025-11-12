#include<bits/stdc++.h>
using namespace std;
int a[999999];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=1,size=0;
	while(l<=n&&r<=n){
		int sum=0;
		for(int i=l;i<=r;i++){
			sum=(sum^a[i]);
		}
		if(sum==k){
			size++;
//			cout<<l<<" "<<r<<" "<<sum<<" "<<size<<endl;
		}
		if(sum>=k){
			l++;
			r++;
		}
		else{
			r++;
		}
	}
	cout<<size;
	return 0;
} 
