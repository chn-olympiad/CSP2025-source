#include<bits/stdc++.h>
using namespace std;
bool check(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum=0,sum2,b[101];
	cin>>n>>m;
	int a[n*m],t=n*m;
	for(int i=0;i<=t-1;i++)cin>>a[i];
	sum2=a[0];
	sort(a,a+t,check);
	for(int i=1;i<=m;i++){
		for(int j=0;j<n;j++){
			sum++;
			cout<<a[sum-1]<<" "<<sum2<<endl;
			if(a[sum-1]==sum2){
				if(sum%j==0)cout<<sum/n<<' '<<n;
				else cout<<sum/n<<' '<<sum%j-1;return 0;
			}
		}i++;
		for(int j=n-1;j>=0;j--){
			sum++;
			cout<<a[sum-1]<<" "<<sum2<<endl;
			if(a[sum-1]==sum2){
				if(sum%j==0)cout<<i<<' '<<n;
				else cout<<i<<' '<<sum%j-1;return 0;
			}
		}
	}
	cout<<1;
}

