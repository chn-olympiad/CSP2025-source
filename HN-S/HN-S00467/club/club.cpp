#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int u=0;u<t;u++){
		int n;
		cin>>n;
		int a[n],b[n],c[n];
		long long b1=0,c1=0;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			b1+=b[i];
			c1+=c[i];
		}
		if(b1==0&&c1==0){
			sort(a,a+n);
			long long sum=0;
			for(int i=n-1;i>=n/2;i--){
				sum+=a[i];
			}
			cout<<sum<<endl;
		}
		if(n==2){
			int sum1[6];
			sum1[0]=a[0]+b[1];
			sum1[1]=a[0]+c[1];
			sum1[2]=b[0]+a[1];
			sum1[3]=b[0]+c[1];
			sum1[4]=c[0]+a[1];
			sum1[5]=c[0]+b[1];
			sort(sum1,sum1+6);
			cout<<sum1[5]<<endl;
		}
	}
	return 0;
}
