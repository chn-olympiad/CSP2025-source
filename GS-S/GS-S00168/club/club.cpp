#include<bits/stdc++.h>
using namespace std;
int t,n,a[10001],sum,k[10001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<3*n;i++){
			cin>>a[i];
		}
		int l=3*n;
		sort(a,a+l);
		for(int i=0;i<n;i++){
			sum+=a[l-i-1];
		}
		cout<<sum;
		sum=0;
	}
	return 0;
}

