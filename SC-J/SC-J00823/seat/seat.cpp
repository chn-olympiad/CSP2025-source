#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int ans[20][20];
int k[400],m,n,rx,ry,r;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>k[i];
	}
	r=k[1];
	sort(k+1,k+m*n+1);
	int x=1,y=1;
	bool s=0;
	for(int i=m*n;i>=1;i--)
	{
		if(r==k[i]){
			rx=x;
			ry=y;
			break;
		}
		ans[x][y]=k[i];
		if(s==0){
			x++;
			if(x>n){
				y++;
				x=n;
				s=1;
			}
		}
		else{
			x--;
			if(x<1){
				y++;
				x=1;
				s=0;
			}
		}
	}
	cout<<ry<<" "<<rx;
	return 0;
}