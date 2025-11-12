#include<bits/stdc++.h>
using namespace std;
int n,m,a[115];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>a[0];
	int sum=1;
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]) sum+=1;
	}
	if(sum%n==0){
		cout<<sum/n<<" "<<n;
	}else{
		cout<<sum/n+1<<" ";
		if(sum/n%2==0){
			cout<<sum%n;
		}else{
			cout<<n-sum%n+1;
		}
	}
	return 0;
	}
