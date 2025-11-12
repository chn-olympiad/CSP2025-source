#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m;
int a[N];
int sum;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	for(int i=2;i<=n*m;i++){
		if(a[i]>a[1])sum++;
	}
	int l=sum/n+1;
	int h;
	if(l%2){
		h=sum%n+1;
	}else{
		h=n-sum%n;
	}
	cout<<l<<" "<<h;
}
