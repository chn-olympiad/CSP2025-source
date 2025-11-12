#include<bits/stdc++.h>
using namespace std;
int n,m,rg,ans;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
cin>>n>>m;
cin>>rg;
a[0]=rg;
for(int i = 1;i<=n*m-1;i++){
	cin>>a[i];
}
sort(a,a+n*m);
if(n==1&&m==1){
	cout<<1<<" "<<1;
}
//erfen
int l = 0,r=n*m-1;
for(int i = 1;i<=(n*m)/i;i++){
	int mid=(l+r)/2;
	if(a[mid]==rg){
		ans = n*m-mid;
	}else if(a[mid]<rg){
		l = mid+1;
	}else{
		r=mid-1;
	}
}

if(int(ceil(ans*1.0/n))%2==0){
	cout<<int(ceil(ans*1.0/n))<<" "<<n-(ans%n)+1;
}else{
	cout<<int(ceil(ans*1.0/n))<<" "<<(ans-n*(int(ceil(ans*1.0/n))-1));
}

	return 0;
}