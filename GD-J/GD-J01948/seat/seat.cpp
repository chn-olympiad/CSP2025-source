#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			cnt++;
		}
	}
	if(cnt%n==0){
		int x=cnt/n;
		cout<<x<<" ";
		if(x%2==1){
			cout<<n;
		}
		else cout<<1;
	}
	else{
		int x=cnt/n+1;
		int a=cnt%n;
		cout<<x<<" ";
		if(x%2==1){
			cout<<a;
		}
		else cout<<n-a+1;
	}
	
	
} 

