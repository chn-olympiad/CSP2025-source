#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	int cnt=0;
	for (int i=1;i<=n*m;++i)cin>>a[i];
	cnt=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int cnt2=1;
	for (int i=1;i<=n*m;++i){
		if (a[i]==cnt)cnt2=i;
	}
	int l=cnt2%n==0?cnt2/n:(cnt2/n)+1;
	int r=(cnt2%n)==0?n:cnt2%n;
	if (l%2==0){
		r=n-r+1;
	}
	cout<<l<<" "<<r;
	return 0;
}
