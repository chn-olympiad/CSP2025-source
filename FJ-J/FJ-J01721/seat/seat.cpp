#include<bits/stdc++.h>
using namespace std;
int m,n,i,a,ra,rpai=1,c,r;
int score[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	memset(score,0,sizeof(score));
	cin>>n>>m;
	cin>>ra;
	score[ra]+=1;
	for(i=2;i<=m*n;i++){
		cin>>a;
		score[a]+=1;
	}
	for(i=100;i>=1;i--){
		if(i==ra) break;
		rpai+=score[i];
	}
	c=(rpai+n-1)/n;
	r=rpai%n;
	if(r==0) r=n;
	if(c%2==0) r=n+1-r;
	cout<<c<<" "<<r;
	return 0;
}
