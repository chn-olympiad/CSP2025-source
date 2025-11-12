#include<bits/stdc++.h>
using namespace std;
long long n,m,in,u=1,R,k=1;
struct seat{
	int x,y;
}s[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>R;
	for(int i=1,j;i<=n;i+=2){
		for(j=1;j<=m;j++){
			s[k].y=i;
			s[k].x=j;
			s[k+m].y=i+1;
			s[k+m].x=m-j+1;
			k++;
		}
		k+=m;
	}
	for(int i=1;i<n*m;i++){
		cin>>in;
		if(in>R)u++;
	}
	cout<<s[u].y<<' '<<s[u].x;
	return 0;
}