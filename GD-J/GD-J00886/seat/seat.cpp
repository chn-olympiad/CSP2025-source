#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=n*m,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]==x) break;
		else if(a[mid]<x){
			r=mid-1;
		}else l=mid+1;
	}
	int j=mid/n;
	int i=mid%n;
	bool ok=0;
	if(mid%(2*n)==0){
		i=1;
		ok=1;
	}else if(i==0){
		i=n;
		ok=1;
	} 
	if(!ok) j++;
	cout<<j<<' '<<i<<' ';
	return 0;
} 
