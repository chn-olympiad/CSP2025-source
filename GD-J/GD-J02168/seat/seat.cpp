#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
int vv,vv1;
double yuchu,zhen;
int x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a[i];
		if(i==1){
			vv=a[i];//标记这人的成绩 
		}
	}
	sort(a+1,a+1+(n*m));
	int cnt=0;
	for(int i=(n+m);i>=1;i--){
		cnt++;
		if(a[i]==vv){
			vv1=i;
		}
	}
	int dog;
	dog=vv1;
	vv1=(n*m)-dog+1;
	if(vv1<=n){
		cout<<1<<' '<<vv1;
		return 0; 
	}
	if(vv1>n){
		x=(vv1%n);
		y=(vv1/n);
		if(x>0)
		{
			y++;
		}
		if((y%2)==0){
			x=n-x+1;
		}
		if(x==0){
			x=n; 
		}
		cout<<y<<" "<<x;
		return 0; 
	}
	return 0;
}
