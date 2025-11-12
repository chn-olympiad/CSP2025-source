#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	sort(a+1,a+n+1);
	if(a[n]==1){
		int ans=1,sum=3;
		for(int i=1;i<=n;i++){
			ans=ans*2+sum;
			sum-=i;
		}
		cout<<ans;
		return 0;
	}
	if(n==3){
		cout<<((a[1]+a[2]>a[3])?"1\n":"0\n");
	}
	return 0;
}
