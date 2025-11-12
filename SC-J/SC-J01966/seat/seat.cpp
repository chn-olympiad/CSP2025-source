#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	freopen("seat.in","r","std.in");
	freopen("seat.out","w","std.out");
	int n,m,x=1,y=0,c,g;
	cin>>n>>m;c=n*m;
	for(int i=0;i<c;i++){
		cin>>a[i];
		if(i==0)g=a[i];
	}
	sort(a,a+c);
	int i=c-1;
	while(a[i]>g){
		if(y<n)y++;
	else {
		if((x+1)%2==1)y=1;
		else y=n;
		x++;
	}
		i--;
	}
	if(y<n)y++;
	else {
		if((x+1)%2==1)y=1;
		else y=n;
		x++;
	}
	cout<<x<<" "<<y;
	return 0;
}