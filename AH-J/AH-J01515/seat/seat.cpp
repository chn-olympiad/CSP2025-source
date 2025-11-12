#include<bits/stdc++.h>
using namespace std;
int n,m,a,tmp,num,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a;
	for(int i=2;i<=n*m;i++){
		cin>>tmp;
		if(tmp>a)
			num++;
	}
	x=num/n,y=num%n;
	y++;
	if(x%2==1)
		y=n-y+1;
	cout<<x+1<<" "<<y;
	return 0;
}
