#include<bits/stdc++.h>
using namespace std;
long long n,m,p,a[105][105],flag;
long long grade[1001],x=1,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>grade[i];
	p=grade[1];
	flag=1;
	sort(grade+1,grade+1+n*m);
	for(int i=n*m;i>=1;i--){
		if(grade[i]==p) return cout<<x<<" "<<y,0;
		if(flag) y++;
		else y--;
		if(y>n) y=n,x++,flag=0;
		if(y<1) y=1,x++,flag=1;
	}
	return 0;
}
