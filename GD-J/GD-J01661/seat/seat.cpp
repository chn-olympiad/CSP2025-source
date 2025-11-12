#include<bits/stdc++.h>
using namespace std;
int x,y,m,n,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x*y;i++) cin>>a[i];
	int t=a[1];
	sort(a+1,a+1+x*y);
	for(int i=1;i<=x*y;i++) if(a[i]==t){t=x*y+1-i;break;}
	if(t%y==0) m=t/y;
	else m=t/y+1;
	if(m%2==1) n=t-(m-1)*y;
	else n=y+1-(t-(m-1)*y);
	cout<<m<<" "<<n;
	return 0;
}
