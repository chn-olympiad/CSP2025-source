#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,i;
}a[10005];
int n,m;
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].i=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,flag=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].i==1){
			break;
		}
		if(flag==1){
			y++;
			if(y==n+1){
				x++;
				y=n;
				flag=0;
			}
		}
		else{
			y--;
			if(y==0){
				x++;
				y=1;
				flag=1;
			}
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
