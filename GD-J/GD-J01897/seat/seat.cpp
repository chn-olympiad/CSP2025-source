#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[1005];int h,l,x,y;int r,num,u,v;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> h >> l;
	for (int i = 1;i <= h*l;i++){
		cin >> a[i];
	}
	r = a[1];
	sort(a+1,a+(h*l)+1,cmp);
	for (int i = 1;i <= h*l;i++){
		if(a[i] == r){
			num = i;
		}
	}
	u = num % h;
	v = num / h;
	if(u > 0){
		v++;
		y = v;
		if(v%2==0){
			x = h+1-u;
		}
		else{
			x = u;
		}
	}
	else{
		y = v;
		x = h;
	}
	//cout << num << endl;
	cout << y << " " << x;
	return 0;
} 

