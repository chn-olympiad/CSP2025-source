#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1007;
int n,m,a[N];

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int sc=a[1];
	sort(a+1,a+n*m+1,[](int x,int y){return x>y;});
	int l=1,r=n*m,pos=0;
	while(l<=r){
		int mid=l+r>>1;
		if(a[mid]>=sc) pos=mid,l=mid+1;
		else r=mid-1;
	}
	int c=(pos-1)/m+1,h=(c%2==1?(pos%m==0?m:pos%m):m+1-(pos%m==0?m:pos%m));
	cout<<c<<" "<<h<<"\n";
	return 0;
}
