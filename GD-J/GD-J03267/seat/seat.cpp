#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+1+n*m,cmp);
	int i=1;
	for(;i<=n*m;i++){
		if(x==a[i]){
			break;
		}
	}
	int y;
	if(i%n!=0){
		y=i/n+1;
		x=i%n;
	}else{
		y=i/n;
		x=n;
	}
	if(y%2==0) x=m-x+1;
	cout<<y<<" "<<x;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
