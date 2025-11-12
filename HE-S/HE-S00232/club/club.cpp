#include<bits/stdc++.h>
using namespace std;
int t,n,sum,sum1,a[1000005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int i=1;i<=n*n;i++){
		cin>>a[i];
	}
	cin>>sum>>sum1;
	for(int i=1;i<=n;i++){
		sort(a,a+n);
		if(i==1){
			int sum=a[i];
		}else if(i==2){
			int sum1=a[i];
		}
	}
	cout<<2*(sum+sum1+2-t)-2*n+1;
	return 0;
}
