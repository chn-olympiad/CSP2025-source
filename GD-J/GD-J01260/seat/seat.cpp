#include<bits/stdc++.h>
using namespace std;
int n,m,t,rk,op,x,y,cnt,a[110];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	  if(a[i]>=t) rk++;
	x=1,y=1,cnt=1,op=1;
	while(cnt<rk){
		if(x+op>=1&&x+op<=n) x+=op,cnt++;
		else{
			if(op==1) op=-1,y++;
			else op=1,y++;
			cnt++;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
/*
4 5
9 1 3 4 5 6 7 8 2 10 11 12 13 14 15 16 17 18 19 20

*/
