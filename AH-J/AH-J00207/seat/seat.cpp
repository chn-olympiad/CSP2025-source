#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],dx,dy,s,num,f,x[15][15],ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=1;i<=s;i++) cin>>a[i];
	ans=a[1];
	sort(a+1,a+1+s);
	dy=0;
	dx=1;
	f=-1;
	while(s>0){
		if(dx==n||dx==1){
			f=f*(-1);
			dy++;
			x[dx][dy]=a[s];
			s--;
		}
		if(f==1) dx++;
		else if(f==-1) dx--;
		x[dx][dy]=a[s];
		s--;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x[i][j]==ans){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
