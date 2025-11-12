#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,x,y,temp,pos=1;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>temp;
	for(int i=2;i<=n*m;i++){
		cin>>x;
		if(x>temp) pos++;
	}
	x=pos/m;
	if(pos%m) x++;
	y=pos%m;
	if(!y) y=n;
	if(!(x%2)) y=n-y+1;
	cout<<x<<" "<<y<<endl;
	return 0; 
}
