#include<bits/stdc++.h>
using namespace std;
int n,m,a[400];
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int cnt=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			cnt=i;
			break;
		}
	}
	int x=cnt/n,y=cnt%n;
	if(y==0){
		x--;
		if(x%2==0)y=n;
		else y=1;
	}
	else if(x%2==1)y=n-y+1;
	cout<<x+1<<" "<<y;
	return 0;
}
