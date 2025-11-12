#include<bits/stdc++.h>
using namespace std;

int n,m,num,x,y,at,z;
int a[110];

bool cmp(int a,int b){
	return a>b;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	int len=n*m;
	
	for(int i=1;i<=len;i++)cin>>a[i];
	
	num=a[1];
	sort(a+1,a+len+1,cmp);
	
	x=1,y=1,at=1,z=1;
	while(num<a[at]){
		at++;
		x+=z;
		if(x>n){
			x=n;z=-1;y++;
		}
		else if(x<1){
			x=1;z=1;y++;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
