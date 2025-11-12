#include<bits/stdc++.h>
using namespace std;
long long t,n;
long long a[4]={};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	long long maxj=0;
	for(int i=1;i<=t;i++){
		cin>>n;
		long long sum=0,mini=0;
		for(int j=1;j<=n;j++){
			cin>>a[1]>>a[2]>>a[3];
			maxj=max(max(a[1],a[2]),a[3]);
			sum+=maxj;
		} 
		cout<<sum<<endl;	
	}
	return 0;
}
