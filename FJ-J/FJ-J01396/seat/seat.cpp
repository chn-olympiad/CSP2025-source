#include<bits/stdc++.h>
using namespace std;

struct stus{
	long long cj;
	bool flag=0;
}a[101];
bool cmp(stus po,stus pt){
	return po.cj>pt.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,zws=0,xb=0,c=0,r=0;
	cin>> n >> m;
	zws=n*m;
	for(long long i = 1; i<=zws; i++){
		cin>> a[i].cj;
	}
	a[1].flag=1;
	sort(a+1,a+zws+1,cmp);
	
	for(long long i = 1; i<=zws; i++){
		if(a[i].flag){
			xb=i;
			break;
		}
	}
	if(xb%n==0){
		c=xb/n;
		if(c%2==1){
			r=n;
		}else{
			r=1;
		}
	}else{
		c=xb/n+1;
		if(c%2==1){
			r=xb%n;
		}else{
			r=n+1-(xb%n);
		}
	}
	cout<< c << " " << r;
	return 0;
}
