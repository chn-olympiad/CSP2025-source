#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,b=0;
	long long k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		}
	if(a[n-1]||k>2){
		cout<<k;
	}
	else{
		cout<<a[k+1]+a[n-1];
	}
} 
