#include<bits/stdc++.h>
using namespace std;
long long i,j,n,m,a[1005],w;
long long l,r;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++){
			scanf("%lld",&a[i]);
	}
	w=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(i=1;i<=n*m;i++){
		if(a[i]==w){
			w=i;
			break;
		}
	}
	l=ceil(w*1.0/n);
	r=w%n;
	if(r==0)r=m;
	if(l%2==0)r=m-r+1;
	cout<<l<<" "<<r;
	return 0;
} 
