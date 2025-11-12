#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,cnt=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>a)cnt++;
	}
    int c=(cnt-1)/n+1;
    cout<<c<<' ';
    int r=cnt-(c-1)*n;
    if(c%2==0)r=n-r+1;
    cout<<r<<endl;
	return 0;
}
