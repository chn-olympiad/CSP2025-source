#include<bits/stdc++.h>
using namespace std;
long long m,n,now,ans=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>now;
	for(int i=1;i<m*n;i++){
		long long x;
		cin>>x;
		if(x>now)ans++;
	}
	long long h=ceil((1.0*ans)/n);
	long long l=ans-(h-1)*n;
	l=(h%2==0?n+1-l:l);
	cout<<h<<" "<<l;
	return 0;
}

