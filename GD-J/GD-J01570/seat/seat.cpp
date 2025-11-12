#include<bits/stdc++.h>
using namespace std;
int n,m,x,cnt=1,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<n*m;i++){
		int num;
		cin>>num;
		if(num>x)cnt++;
	}
	c=cnt/(2*n)*2+1,cnt=cnt%(2*n);
	if(cnt<=n)r=cnt;
	else c++,r=2*n-cnt+1;
	cout<<c<<" "<<r;
	return 0;
}
