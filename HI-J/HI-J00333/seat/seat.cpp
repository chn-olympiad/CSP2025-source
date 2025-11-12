#include<bits/stdc++.h>
using namespace std;
long long n,m,a[110],x;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m>>x;a[0]=x;
    for(long long i=1;i<n*m;i++){
    	cin>>a[i];
	}sort(a,a+n*m);
	for(long long i=0;i<n*m;i++){
		if(a[i]==x){
			long long b=m*n-i;
			if(b%m>0)cout<<(b-b%m+m)/m;
			else cout<<b/m;
			cout<<' ';
			if(b>n){
				if((b-b%m+m)/m%2)cout<<(b-b%n)/n;
				else cout<<m-(b-b%n)/n+1;
			}
			else cout<<b;
			break;
		}
	}
 return 0;
}

