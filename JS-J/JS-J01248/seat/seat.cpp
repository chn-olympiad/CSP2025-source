#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n*m;i++){
	    cin>>a[i];
	    if (a[i]>a[0])
	      cnt++;
	}
	for (int i=0;i<m;i++){
		if (i*n<=cnt&&i*n+n>cnt){
			cout<<i+1<<' ';
			if (i%2==0)
			  cout<<cnt-i*n+1;
			else
			  cout<<n-(cnt-i*n);
			return 0;
		}
	}
	return 0;
}
