#include<iostream>
#include<algorithm>
using namespace std;
int mp[105][105];
struct node{
	int id,val;
}a[10005];
int n,m,c,r,x,y;
bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].val;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	x=1;y=1;
	int cnt=0;
	while(cnt<=n*m){
		while(y<=n){
			if(a[++cnt].id==1){
				c=x,r=y;
			}
			y++;
		}
		y--;
		x++;
		if(x>m)break;
		while(y>=1){
			if(a[++cnt].id==1){
				c=x,r=y;
			}
			y--;
		}
		y++;
		x++;
		if(x>m)break;
	}
	cout<<c<<" "<<r;
	return 0;
}
/*
2 2
99 100 97 98

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/

