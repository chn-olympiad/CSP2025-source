#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],sum;
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
