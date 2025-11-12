#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[11][11]={0},cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cnt=a[1];
	sort(a+1,a+n*m+1);
	int sum=0;
	for(int i=n*m;i>=1;i--){
		sum++;
		if(a[i]==cnt){
			break;
		}
	}
	cout<<(sum+n-1)/n<<" ";
	if(((sum+n-1)/n)%2==1){
		if(sum%n==0){
			cout<<n;
			return 0;
		}
		cout<<sum%n;
		return 0;
	}
	cout<<n-sum%n+1;
	return 0;
} 
