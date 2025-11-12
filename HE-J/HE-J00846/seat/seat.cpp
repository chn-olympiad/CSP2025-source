#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n,m,a[N],res,idxres;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt = n*m;
	for(int i=1;i<=cnt;i++) cin>>a[i];
	res = a[1];
	sort(a+1,a+cnt+1,cmp);
	int l=1,r=cnt;
	while(l<=r){
		int mid = l+(r-l)/2;
		if(a[mid]==res){
			idxres = mid;
			break;
		}else if(a[mid]>res){
			l = mid+1;
		}else r = mid-1;
	}
	int X = ceil(1.0*idxres/n); 
	cout<<X<<' ';
	int Y = idxres-n*(X-1);
	if(X%2==0){
		cout<<n+1-Y;
	}else{
		cout<<Y;
	}
	return 0;
}
