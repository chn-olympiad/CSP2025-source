#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
struct Node{
	LL x,y;
}a[110];
bool cmp(Node &x,Node &y){
	return x.x>y.x;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a+1,a+n*m+1,cmp);
	LL x=1,y=0;
	for(LL i=1;i<=n*m;i++){
		if(x%2==1) y++;
		else y--;
		if(y>n||y<=0){
			x++;
			if(x%2==0) y=n;
			else y=1;
		}
		if(a[i].y==1){
			cout<<x<<" "<<y;
			break;
		} 
	}
	return 0;
}
