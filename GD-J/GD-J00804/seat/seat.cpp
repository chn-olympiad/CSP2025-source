//2-seat
#include<bits/stdc++.h>
using namespace std;
int a[1000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p;
	cin>>n>>m>>p;
	a[1]=p;
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(p==a[i]){
			cout<<y<<" "<<x<<endl;
			return 0;
		}
		if(x==n&&y%2==1)y++;
		else if(x==1&&y%2==0)y++;
		else if(y%2==1)x++;
		else x--;
	}
	return 0;
}
