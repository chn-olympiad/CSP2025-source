#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '/n'
int n,m;
int a[105];
int q_x,xy;

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int z=n*m;
	for(int i=1;i<=z;i++){
		cin>>a[i];
	}
	xy=a[1];
	sort(a,a+z+1);
	for(int i=z;i>=1;i--){
		if(a[i]==xy){
			q_x=z-i+1;
			break;
		}
	}
	int c=(q_x+n-1)/n,r=q_x%n;
	cout<<c<<" ";
	if(c%2==1){
		if(r==0){
			cout<<n;
		}else{
			cout<<r;
		}
	}else{
		if(r==0){
			cout<<1;
		}else{
			cout<<n-r+1;
		}
	}
	return 0;
}
