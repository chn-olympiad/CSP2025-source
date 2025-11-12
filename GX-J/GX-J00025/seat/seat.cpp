#include<bits/stdc++.h>
using namespace std;
int n,m,d,x=0,y=1,r,a[110],s;
bool cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	d=n*m;
	for(int i=1;i<=d;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+d+1,cmp);
	for(int i=1;i<=d;i++){
		if(r==a[i]){
			s=i;
		}
	}
	cout<<s<<endl;
	for(int i=1;i<=s;i++){
		if(y%2==1){
			x++;
			if(x-1==n){
				y++;
			}
		}
		if(y%2==0){
			x--;
			if(x==0){
				x++;
				y++;
			}
		}
	}
 	cout<<y<<" "<<x;
return 0;
}
