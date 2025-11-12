#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdin);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[105],x;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	x=a[0];
	int i=n*m-1,y=1,z=1;
	sort(a,a+n*m);
	bool b=false;
	while(a[i]!=x){
		if(!b) y++;
		else y--;
		if(y>n){
			b=true;
			y--;
			z++;
		}else if(y<1&&z!=1){
			b=false;
			y++;
			z++; 
		}
		i--;
	}
	cout<<z<<" "<<y;
	return 0;
}
