#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int INF=1e3+10;
int a[INF],pos,cnt,num;

bool cmp(const int a1,const int a2){
	return a1>a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	cnt=n*m;
	for (int i=1;i<=cnt;i++)cin>>a[i];
	pos=a[1];
	sort(a+1,a+1+cnt);
	int p=lower_bound(a+1,a+1+cnt,pos)-a;
	p=cnt-p+1;
	sort(a+1,a+1+cnt,cmp);
	int x=1,y=1,dr=1;
	while(x<=n&&y<=m){
		num++;
		if (num==p){
			cout<<y<<" "<<x;
			break;
		}
		x+=dr;
		if (x>n)x=n,y++,dr=-1;
		else if (x<1)x=1,y++,dr=1;
	}
	return 0;
}
