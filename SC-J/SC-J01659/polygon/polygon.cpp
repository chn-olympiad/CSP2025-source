#include<bits/stdc++.h>
using namespace std;
long long MOD= 998244353;
int n,a[5005],mx=0;
long long sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int ins=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			ins+=a[j];
			mx=max(mx,a[j]);	
		}
		if(2*mx<ins)sum++;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}