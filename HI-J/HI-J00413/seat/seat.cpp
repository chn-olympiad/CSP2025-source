#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
long long x,y,temp,pos;
bool back;
long long a[1000];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	k=n*m;
	for (long long i= 1 ; i <= k ; i ++ ) {
		cin >> a[i];
	}
		
	temp = a[1];
	sort(a+1,a+k+1,cmp);

	for (long long i = 1 ; i <= k; i ++ ) {
		//cout << a[i] << endl;
		if (a[i] == temp){
			pos = i;
			break;
		}
	}
	
	x = pos/n;
	bool l=false;
	//cout << pos << endl;
	if (pos%n != 0){
		x ++;
		l=true;
	}
	back = x%2==0?true:false;
	if(!l){
		//cout << back << " " << x << endl;
		y=back?1:n;
		//cout << "h";
	}
	else{
		if (back){
			y = n-pos%n+1;
		}
		else{
			y = pos%n;
		}
	}
	cout << x << " " << y;
	return 0;
}

