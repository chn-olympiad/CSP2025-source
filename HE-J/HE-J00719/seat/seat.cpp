#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int x;
int xp[1010];
int a[15][15];
bool cmp(int x,int y){
	return x>=y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	cin>>n>>m;
	cin>>xp[1];
	x=xp[1];
	for(int i=2;i<=n*m;i++){
		cin>>xp[i];	
	}
	int t=0;
	sort(xp+1,xp+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==xp[i])t=i;
	}
	//for(int i=1;i<=n*m;i++)cout<<xp[i]<<' ';
	//cout<<'\n';
	//cout<<t<<'\n';
	int xl=t/n;
	int yl=t%n;
	//cout<<yl;
	if(yl==0)yl=m;
	else xl++;
	if(xl%2)cout<<xl<<' '<<yl;
	else cout<<xl<<' '<<m-yl+1;
	return 0;
}
