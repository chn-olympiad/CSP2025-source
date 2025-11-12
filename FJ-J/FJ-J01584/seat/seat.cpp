#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		if(i==0) cin>>s;
		else cin>>a[i];
	}
	sort(a+1,a+n*m,cmp);
	int l=1,r=n*m-1,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(a[mid]>s&&s>a[mid+1]) break;
		else if(a[mid]<s) r=mid-1;
		else l=mid+1;
	} 
	mid++;
	int li=(mid-1)/n+1;
	cout<<li<<" ";
	int hang=mid-(li-1)*n;
	if(li%2==1){
		cout<<hang;
	}else cout<<n-hang+1;
	return 0;
}
