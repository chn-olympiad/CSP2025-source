#include<bits/stdc++.h>
using namespace std;
int n,m;
int xx=1,yy=1;
int a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int t=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(a[i]==t)cout<<xx<<" "<<yy;
		if((yy==n)&&(xx%2==1))yy=n,xx++;
		else if((yy==1)&&(xx%2==0))yy=1,xx++;
		else if(xx%2==0)yy--;
		else yy++;
	}
	return 0;
} 
