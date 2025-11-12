#include<bits/stdc++.h>
using namespace std;
int n,m;
struct no{
	int x,i;
}a[105];
bool cmp(no a,no b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].i=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,turn=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].i==1){
			cout<<y<<" "<<x<<endl;
			return 0;
		}
		if(x==n&&turn==1){
			turn=-1;
			y++;
		}
		else if(x==1&&turn==-1){
			turn=1;
			y++;
		}
		else x+=turn;
	}
	return 0;
}
