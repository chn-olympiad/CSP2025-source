#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1100],ans,x=0,y=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long len=n*m,num;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+len+1);
	for(int i=len;i>0;i--){
		if(a[i]==num){
			ans=len-i+1;
			break;
		}
	}
	long long dx=1,dy=0;
	int z=0;
	for(int i=1;i<=ans;i++){
		x+=dx;
		y+=dy;
		if(z==1){
			dy=0,dx=-1;
			z=0;
		}
		if(z==2){
			dy=0,dx=1;
			z=0;
		}
		if((x+dx)>n){
			dx=0,dy=1,z=1;
		}
		if((x+dx)<1){
			dx=0,dy=1,z=2;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}