#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],idx;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	idx=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=n*m,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]>idx) l=mid+1;
		else if(a[mid]<idx) r=mid-1;
		else break;
	}
	int ans=0;
	if(((mid+n-1)/n)%2==0){
		if(mid%n==0) ans=n;
		else ans=n-(mid%n)+1;
		cout<<(mid+n-1)/n<<" "<<ans;
	}else{
		if(mid%n==0) ans=n;
		else ans=mid%n;
		cout<<(mid+n-1)/n<<" "<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
