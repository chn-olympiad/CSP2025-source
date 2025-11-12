#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]>a[1][1])sum++;
		}
	}
	int x=a[1][1];
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	if(n==1&&m<=10){
		cout<<1<<" ";
		int ans=1;
		for(int i=1;i<=m;i++){
			if(a[1][i]>x){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=10&&m==1){
		int ans=1;
		for(int i=1;i<=n;i++){
			if(a[i][1]>x){
				ans++;
			}
		}
		cout<<ans<<" "<<1;
		return 0;
	}
	int y=sum/n;
	if(sum%n!=0){
		y=y+1;
	}
	cout<<y<<" ";
	if(y%2==0){
		if(sum%n==0){
			cout<<1;
			return 0;
		}
		cout<<n-(sum%n)+1;
	}else{
		if(sum%n==0){
			cout<<n;
			return 0;
		}
		cout<<sum%n;
	}
	return 0;
}
