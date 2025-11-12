#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],rcj,r,c=1;
bool cmp(int a,int b){
	return a>b;
}
int find(){
	int l=1,r=n*m,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==rcj){
			ans=mid;
			break;
		}
		else if(a[mid]<rcj)r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	rcj=a[1];
	sort(a+1,a+n*m+1,cmp);
	r=find();
	while(r>n)r-=n,c++;
	cout<<c<<" "<<r;
	return 0;
}
