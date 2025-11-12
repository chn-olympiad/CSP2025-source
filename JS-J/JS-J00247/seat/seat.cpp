#include<bits/stdc++.h>
using namespace std;
int n,m,x,num=1,ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<(n*m);i++){
		int y;
		cin>>y;
		if(y>x)num++;
	}
	int xx=(num-1)%n+1,yy=num/n;
	if(xx!=0&&xx!=n)yy++;
	ans1=yy;
	if(yy%2==0)ans2=n-xx+1;
	else ans2=xx;
	cout<<ans1<<" "<<ans2<<" ";
	return 0;
}
