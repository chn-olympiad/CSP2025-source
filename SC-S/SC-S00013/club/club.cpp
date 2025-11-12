#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int t,n;
int ans[200005];
int a[200005],b[200005],c[200005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int j=1;j<=200005;j++){
			a[j]=0;
			b[j]=0;
			c[j]=0;
			ans[j]=0;
		}
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		sort(c+1,c+1+n);
		int sum=n/2+1;
		for(int j=1;j<=n/2*3;j++){
			if(sum>n) sum=n/2+1;
			if(j<=n/2) ans[j]=a[sum];
			else if(j<=n) ans[j]=b[sum];
			else ans[j]=c[sum];
			sum++;
		}
		sort(ans+1,ans+1+n/2*3);
		long long int isum=0;
		for(int j=n/2+1;j<=n/2*3;j++){
			isum+=ans[j];
		}
		cout<<isum<<endl;
	}
	return 0;
}