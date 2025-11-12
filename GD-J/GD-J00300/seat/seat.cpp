#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int s,ss;
}a[10005];
int n,m;
int b[1005][1005],id=1;
int cmp(node x,node y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].ss=i;
	} 
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1;
	while(id<=n*m){
		while(x<=n&&b[x][y]==0){
			if(a[id].ss==1){
				cout<<y<<" "<<x;
				return 0;
			}
			b[x][y]=a[id].s;
			x++;
			id++;
		}
		x--;
		y++;
		while(x>=1&&b[x][y]==0){
			if(a[id].ss==1){
				cout<<y<<" "<<x;
				return 0;
			}
			b[x][y]=a[id].s;
			x--;
			id++;
		}
		x++;
		y++;
	}
	return 0;
}
