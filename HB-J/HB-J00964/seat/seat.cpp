#include<bits/stdc++.h>
using namespace std;
int a[11][11],m[110],b,c,d;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.in","w",stdout);
	cin>>b>>c;
	for(int i=1;i<=b*c;i++){
		cin>>m[i];
	}
	d=m[1];
	sort(m+1,m+b*c+1);
	for(int i=1;i<=b*c;i++){
		if(m[i]==d){
			d=b*c-i+1;
			break;
		}
	}
	int x,y;
	x=d/c;
	y=d%c;
	if(x%2==0){
		cout<<x+1<<" "<<y;
	}
	else{
		cout<<x+1<<" "<<c-y+1;
	}




	return 0;
}
