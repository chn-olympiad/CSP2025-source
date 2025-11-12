#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,x,c,d;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(x==a[i]){
			x=i;
			break;
		}
	}
	c=x/(m*2);
	d=x%(m*2);
	if(d==0){
		cout<<1<<' '<<c*2<<endl;
		return 0;
	}
	if(d>m){
		cout<<c*2+2<<' '<<m-(d-m)+1<<endl;
	}else{
		cout<<c*2+1<<' '<<d<<endl;
	}
	return 0;
}
