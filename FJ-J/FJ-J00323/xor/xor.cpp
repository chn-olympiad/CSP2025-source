#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int ns[MAXN];
int yh(int x,int y){
	int yr=0;
	bool xp=0,yp=0;
	for(int i=20;i>=0;i--){
		xp=0;
		yp=0;
		int p=pow(2,i);
		if(p<=x){
			xp=1;
			x-=p;
		}
		if(p<=y){
			yp=1;
			y-=p;
		}
		if((xp||yp)&&(!(xp&&yp)))yr+=p;
	}
	return yr;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)cin >> ns[i];
	int ny=0,q=0;
	int b=n;
	bool hpq=false;
	for(int i=1;i<=n;i++){
		ny=ns[i];
		if(i>b){
			b=n;
			hpq=false;
		}
		for(int j=i;j<=b;j++){
			if(ny==k){
				if(!hpq){
					q++;
					hpq=true;
				}
				b=j;
				break;
			}
			if(j<b)ny=yh(ny,ns[j+1]);
		}
	}
	cout << q;
	return 0;
}
