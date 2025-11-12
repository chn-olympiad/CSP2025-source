#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	int k;
	int a[500005];
	cin>>n>>k;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) sum++;
	}
	cout<<sum;
	
	
	
	return 0;
}
