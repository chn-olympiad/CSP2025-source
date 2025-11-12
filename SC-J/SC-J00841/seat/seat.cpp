#include<bits/stdc++.h>
using namespace std;
struct S{
	int a,b;
	bool operator <(S x){
		return a>x.a;
	}
}z[1000];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>z[i].a;
		z[i].b=i;
	}
	sort(z,z+n*m);
	int x=1,y=1,k=1;
	bool flag=0;
	for(int i=0;i<n*m;i++){
		if(z[i].b==0){
			cout<<y<<" "<<x;
			return 0;
		}
		if(x==n&&flag){
			k=-1;
			y++;
			flag=0;
		}else if(x==1&&flag){
			k=1;
			y++;
			flag=0;
		}else x+=k,flag=1;
	}
	return 0;
}
/*
AK CSP-J
AK CSP-S
AK NOIP
AK 省选
AK NOI
AK IOI
*/