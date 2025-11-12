#include<bits/stdc++.h>
using namespace std;
long long n,m,z,y=1;
long long a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	long long sum=a[1];
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1);
	int l=0;
	for(int i=n*m;i>=1;i--){
		l++;
		if(a[i]==sum) z=l;
	}
	//cout<<z<<endl;
	while(z>n){
		z-=n;
		y++;
	}
	cout<<y<<" ";
	if(y%2==0){
		z=n-z+1;
		cout<<z;
	}
	else cout<<z;
	return 0;
}
