#include<bits/stdc++.h>
using namespace std;
int a[5001],n;
long long as;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1||n<3){
		cout<<0;
		return 0;
	}
	for(int i=n;i>=3;i--){
		int z=a[n]*2;
		int k=0,s=0;
		while(s>z){
			k++;
			s+=a[n-k];
		}
		long long l=1;
		for(int j=2;j<k;j++){
			l*=j;
			as+=l*(k-1-j);
		}
	}
	cout<<as;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
