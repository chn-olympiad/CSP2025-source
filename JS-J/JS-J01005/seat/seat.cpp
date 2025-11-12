#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,f,s;
int h,l;
int a[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+k+1);
	s=lower_bound(a+1,a+k+1,f)-a;
	s=k-s+1;
	if(s%m==0){
		l=s/m;
		s=m;
	}
	else {
		l=s/m+1;
		s-=(l-1)*m;
	}
	if(l%2!=0){
		h=s;
	}
	else h=m-s+1;
	cout<<l<<" "<<h<<endl;
	return 0;
}
