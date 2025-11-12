#include<iostream>
#include<algorithm>
using namespace std;
int a[110];
bool tmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,y=1,k,l,r,mid,ans=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	k=a[0];
	sort(a,a+n*m,tmp);
	l=0;
	r=n*m-1;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]>k)l=mid+1;
		else if(a[mid]<k)r=mid-1;
		else break;
	}
	for(int i=1;i<=m;i++){
		for(int j=i%2?1:n;i%2?j<=n:j>0;i%2?j++:j--){
			if(ans==mid){
				cout<<i<<" "<<j;
				return 0;
			}
//	cout<<ans<<" "<<mid<<endl;
			ans++;
		}
	}
	return 0;
}
