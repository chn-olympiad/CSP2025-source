#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	
	//freopen("seat.in","r","stdin");
	//freopen("seat.out","w","stdout");
	
	long long m,n,c=0,r=0,R,ans=0,l,ri,mid;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
		if (i==1) R=a[i];
	}
	sort(a+1,a+m*n+1,cmp);
	l=0,ri=m*n+1;
	mid=(l+ri)/2;
	while (l+1!=ri){
		mid=(l+ri)/2;
		if (a[mid]>=R){
			l=mid;
			ans=mid;
		}
		else{
			ri=mid;
		}
	}
	if (ans%n==0) c=ans/n;
	else c=ans/n+1;
	if (c%2==1){
		if (ans%n==0) r=n;
		else r=ans%n;
	}
	else {
		if (ans%n==0) r=1;
		else r=n-ans%n+1;
	}
	
	cout<<c<<" "<<r;
	return 0;
}
