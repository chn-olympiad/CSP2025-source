#include<bits/stdc++.h >
using namespace std;
int m,n,s,a[102],pl;
bool hs(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	cin >>n>>m>>a[1];
	s=a[1];
	for (int i=2;i<=m*n;i++){
		cin >>a[i];
	}
	sort(a+1,a+m*n+1,hs);
	int l=1,r=m*n;
	int mid;
	while (l<r){
		mid=(l+r)/2;
		if(a[mid]>s)l=mid+1;
		else if(a[mid]<=s)r=mid;
	}
	pl=l-1;
	int x=pl/n+1;
	int y=pl%n+1;
	cout <<x<<" ";
	if(!x%2)cout<<n-y+1;
	else cout<<y;
	return 0;
}