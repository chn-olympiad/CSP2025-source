#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[105];
int pos;
bool cmp(int x,int y){return x>y;}
int x,y;
int dir=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i];
	pos=a[1];
	x=1,y=1;
	sort(a+1,a+n*m+1,cmp);
	int cnt=1;
	while (pos!=a[cnt]){
		x+=dir;
		if (x>n) x--,dir=-1,y++;
		else if (x<1) x++,dir=1,y++;
		cnt++;
	}
	cout<<y<<" "<<x;
	return 0;
}
//rp++;

