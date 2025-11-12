#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a[100000],i,n,t;
	cin>>t>>n;
	for(i=1;i<=3*n;i++){
	cin>>a[i];
	}
	sort(a+1,a+3*n+1);
	cout<<a[3*n]+a[3*n-1]+a[3*n-2]<<endl;
	return 0;
}
