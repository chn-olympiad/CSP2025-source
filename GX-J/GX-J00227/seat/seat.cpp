#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long n,pai = 0,m,a[N],c,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>a[i];
	}
	long long R = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++){
		if(a[i] == R){
			pai = i;
			break;
		}
	}
	//cout<<"Pai"<<pai<<endl;
	//c = liehsu
	c = ceil(double(pai) / double(n));
	//cout<<c<<"And"<<d;
	//2,4,6,8,10,12......
	if(c % 2 == 0){
		r =  n-(pai - (c-1) * n) + 1;
	}else {
		r = pai - (c-1) * n;
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
