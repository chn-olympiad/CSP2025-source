#include <bits/stdc++.h>
using namespace std;
long long int n,k;
int a[1000001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long int s=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			if(s<=2*a[i]){
				cout<<0;
				return 0;
			}
		}
		cout<<1;
	}
	return 0;
}