#include<bits/stdc++.h>
using namespace std;
int n,m,x=1,y=1,b=1;
struct rd{
	int te,de;
}a[100];
bool cmd(rd ya,rd yb){
	return ya.te>yb.te;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].te;
		a[i].de=i+1;
	}
	sort(a,a+n*m,cmd);
	for(int i=0;i<m*n;i++){
		if(a[i].de==1)cout<<x<<" "<<y;
		y+=b;
		if(y==0)b=1,x++,y++;
		if(y==n+1)b=-1,x++,y--;
	}
	return 0;
}
