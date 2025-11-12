#include<bits/stdc++.h>
using namespace std;
bool cmp(int f,int s){
	return f>s;
}
int n,m,x=1,y=1,r;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(r==a[(i-1)*n+j]){
				cout<<x<<' '<<y;
				return 0;
			}
			if(j==n)x++;
			else if(i%2)y++;
			else if(i%2==0)y--;
		}
	}
	return 0;
}
