#include<bits/stdc++.h>
#include<string>
using namespace std;
int n,k;
int qj(int l,int a[],int ans){
	int sum=a[l];
	for(int i=l;i<=n;i++){
		if(sum==k){
			return qj(i+1,a,ans+1);
		}
		sum=sum^a[i];
	}
	return ans;
}
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ma=0;
	for(int i=0;i<n;i++){
		ma+=qj(i,a,0);
	}
	cout<<ma;
	return 0;
}