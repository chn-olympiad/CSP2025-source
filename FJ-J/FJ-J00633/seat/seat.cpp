#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=1;
int a[110];
signed main(){
 	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]){
			ans++;
		}
	}
	int x,y;
	if(ans%m==0){
		x=ans/m;
	}else{
		x=ans/m+1;
	}
	if(ans%n==0){
		y=n;
	}else{
		y=ans%n;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
} 
