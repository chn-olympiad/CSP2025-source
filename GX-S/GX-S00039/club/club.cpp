#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,sum=0;
	cin>>t;
	for(int i=1;i<=t;i++){
		long long n,a[4];
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[1]>>a[2]>>a[3];
			if(a[1]>=a[2]&&a[1]>=a[3])sum+=a[1];
			else if(a[2]>=a[3]&&a[2]>=a[1])sum+=a[2];
			else sum+=a[3];
		}
		cout<<sum;
	}
	return 0;
}
