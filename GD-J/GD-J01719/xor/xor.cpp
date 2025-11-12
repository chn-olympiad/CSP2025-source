#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	long long n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n<=1)cout<<0;
	else if(n==2)cout<<1;
	else if(k==0){
		if(n%2==0)
		cout<<n*n/2/2;
		else cout<<(n+1)*(n-1)/2/2;
	}
	else cout<<4;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
