#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,a[100005],r,c;
bool cmp(int a,int b){
	return a > b;
}
int b,pos;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++){
		if(a[i] == b){
			pos=i;
		}
	}
	c=ceil(1.0*pos/n);
	if(m == 1){
		cout << pos/n << " " << 1;
		exit(0);
	}
	else if(n == 1){
		cout << 1 << " " << pos%m;
		exit(0);
	}
	else if(pos%m==0 && c%2!=0){
		r=m-pos/m+1;
	}
	else if(pos%m==0 && c%2==0){
		r=1;
	}
	else if(pos%m!=0 && c%2 != 0){
		r=pos%m;
	}
	else if(pos%m!=0 && c%2 == 0)
	{
		r=m-pos%m+1;
	}
	cout << c << " " << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
