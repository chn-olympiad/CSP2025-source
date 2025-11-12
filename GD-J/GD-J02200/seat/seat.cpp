#include<bits/stdc++.h>
using namespace std;
long long n,m,k,k1,cnt,u;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
     u=n*m;
	cin>>k;
	for(int i=1;i<u;i++){
		cin>>k1;
		if(k<k1)cnt++;
	}
		if((cnt/n+1)%2==0)cout<<cnt/n+1<<' '<<n-cnt%n;
		else cout<<cnt/n+1<<' '<<cnt%n+1;
	return 0;
} 
