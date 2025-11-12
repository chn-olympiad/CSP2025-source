#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn=+10;
int n,m,a,R,cnt,s,y,c,r;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>a;
	R=a;
	for(int i=2;i<=n*m;i++){
		cin>>a;
		if(a>R) cnt++;
	}
	cnt++;
	s=cnt/(n*2);
	y=cnt-s*(n*2);
	c=s*2;
	if(y==0) r=1;
	else if(y>0&&y<=n){
		c+=1;
		r=y;
	}
	else if(y>n&&y<n*2){
		c+=2;
		r=n*2-y+1;
	}
	cout<<c<<" "<<r<<endl;		
	return 0;
}