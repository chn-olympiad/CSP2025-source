#include <bits/stdc++.h>
using namespace std;
const int N=200;
int a[N];
int n,m;
int sum=0;
int pos=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>a[i];
		if(i==1)sum=a[i];
	}
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=(n*m);i++){
		if(sum==a[i])
		{
			pos=i;
			break;
		}
	}
	//cout<<pos<<endl;
	int x=0,y=0;
	if(pos%n==0){
		x=pos/n;
		y=n;
	}
	else{
		x=pos/n+1;
		if(x%2==1)
		{
			y=pos%n;
		}
		else{
			y=n-(pos%n)+1;
		}
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
