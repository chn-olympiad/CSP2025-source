#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sum=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])sum++;
	}
	int x=1,y=1;
	while(sum--){
		if(x&1)y++;
		else y--;
		if(y>n)x++,y--;
		if(y<1)x++,y++;
		//cerr<<x<<' '<<y<<'\n';
	}
	cout<<x<<' '<<y;
	return 0;
}

