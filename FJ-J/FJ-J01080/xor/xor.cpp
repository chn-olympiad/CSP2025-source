#include<bits/stdc++.h>
using namespace std;
int a,sum=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==k)sum++;
	}
	cout<<sum;
	return 0;
}
