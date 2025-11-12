#include<bits/stdc++.h>
using namespace std;
int n,m,w=1;
int r,b;
int x,y,z;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	x=y=1;
	for(int i=2;i<=n*m;i++){
		cin>>b;
		if(b>r) w++;
	}
	for(int i=1;i<=m;i++){
		int bj;
		if(i%2==1) bj=1;
		else bj=-1;
		for(int j=1;j<=n;j++){
			z++;
			if(z==w){
				cout<<x<<" "<<y;
			}
//			cout<<x<<" "<<y<<endl;
			y+=bj;
		}
		x++;
		y-=bj;
	}
	return 0;
}

