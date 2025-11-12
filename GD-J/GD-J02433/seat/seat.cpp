#include<bits/stdc++.h>
using namespace std;
int a[500];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k,len=n*m;
	cin>>k;
	a[1]=k;
	for(int i=2;i<=len;i++)cin>>a[i];
	sort(a+1,a+len+1,cmp);
	int x=1,y=1,tot=1;
	while(tot<=len){
		if(a[tot]==k)break;
		if(x%2==1)y++;
		else y--;
		if(y>n){
			y=n;
			x++;
		}
		if(y<1){
			y=1;
			x++;
		}
		tot++;
	}
	cout<<x<<" "<<y;
	return 0;
}
