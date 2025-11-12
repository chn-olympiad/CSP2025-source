#include<bits/stdc++.h>
using namespace std;
long long n,m,h,l;
long long test[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>test[i];
	}
	long long r=test[1];
	sort(test+1,test+n*m+1); 
	for(int i=n*m,j=1;i>=1;i--,j++){
		if(test[i]==r){
			r=j;
			break;
		}
	}
	if(r%n==0){
		long long x=r/n;
		if(x%2==0){
			l=x;
			h=1;
		}else{
			l=x;
			h=n;
		}
	}else{
		long long y=r/n+1;
		if(y%2==0){
			l=y;
			h=n-(r-(y-1)*n)+1;
		}else{
			l=y;
			h=r-(y-1)*n;
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
