#include<bits/stdc++.h>
using namespace std;
struct node{
	int s,i;
}a[110];
int n,m,x,y,k;
bool cmp(node x,node y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].i=i;
	}
	sort(a+1,a+1+n*m,cmp);
	x=0;
	y=1;
	k=0;
	while(x!=n||y!=m){
		while(x!=n){
			x++;
			if(a[++k].i==1){
				cout<<y<<" "<<x;
				return 0;
			}
		}
		if(y!=m){
			y++;
			if(a[++k].i==1){
				cout<<y<<" "<<x;
				return 0;
			}
		}
		while(x!=1){
			x--;
			if(a[++k].i==1){
				cout<<y<<" "<<x;
				return 0;
			}
		}
		if(y!=m){
			y++;
			if(a[++k].i==1){
				cout<<y<<" "<<x;
				return 0;
			}
		}
	}
	return 0;
}
