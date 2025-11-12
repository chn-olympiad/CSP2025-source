#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
		ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int nm=n*m,a[nm+10],ans=0;
	for(int i=1;i<=nm;i++){
		cin>>a[i];
		int s=a[1];
		if(a[i]>s){
			ans++;
		}
	}int sum=ans/n+1;
	int sun=ans%n;
	if(sum%2==1){
		cout<<sum<<" "<<sun+1<<endl;
	}else{
		cout<<sum<<" "<<n-sun<<endl;
	}
	return 0;
}
