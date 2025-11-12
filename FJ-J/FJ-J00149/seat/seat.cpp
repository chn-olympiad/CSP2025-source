#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int a[205],n,m;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n*m;i++){
		cin >>a[i];
	}
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(k==a[i]){
			k=i;
			break;
		}
	}
	//cout << k;
	int x=k%n,y=k/n;
	if(y%2==0){
		if(x==0)cout << y<<' '<<1<<'\n';
		else {
			cout << y+1<<' '<<x<<'\n';
		}
	}
	else {
		if(x==0)cout << y<<' '<<n<<'\n';
		else {
			cout << y+1<<' '<<n-x+1<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
