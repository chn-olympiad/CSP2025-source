#include<bits/stdc++.h>
using namespace std;
int x,y,s,n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=2;i<=n*m;i++){
		cin>>y;
		if(y>x)s++;
	}
	if((s/n)%2==1)cout<<s/n+1<<' '<<n-(s%n);
	else cout<<s/n+1<<' '<<(s%n)+1;
	return 0;
} 
