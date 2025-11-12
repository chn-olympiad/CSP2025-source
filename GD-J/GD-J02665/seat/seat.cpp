#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int R=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int x=1,y=1,dx=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==R)return cout<<y<<" "<<x,0;
		if(x==n&&dx==1)y++,dx=-1;
		else if(x==1&&dx==-1)y++,dx=1;
		else x+=dx;
	}
	return 0;
}
