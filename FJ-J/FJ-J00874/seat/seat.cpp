#include<bits/stdc++.h>
using namespace std;

struct student{
	int cj,id;
}a[105];

bool cmp(student x,student y){
	return x.cj > y.cj;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1 ; i<=n*m ; i++){
		cin >> a[i].cj;
		a[i].id = i;
	}
	sort(a+1,a+n*m+1,cmp);
	int wei;
	for(int i=1 ; i<=n*m ; i++){
		if(a[i].id == 1){
			wei = i;
			break;
		}
	}
	int h = wei/n+(wei%n!=0),w;
	if(h%2 == 1){
		if(wei%n == 0) w = n;
		else w = wei%n;
	}else{
		if(wei%n == 0) w = 1;
		else w = n-wei%n+1;
	}
	cout << h << ' ' << w;
	return 0;
}
