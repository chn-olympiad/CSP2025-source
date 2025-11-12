#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct seat{
	long long s;
	bool r;
}a[105];

bool cpr(seat a,seat b){
	return a.s > b.s;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,tmp;
	cin >> n >> m >> tmp;
	a[0] = {tmp,true};
	for(long long i = 1;i < n*m;i++){
		cin >> tmp;
		a[i] = {tmp,false};
	}
	sort(a,a+n*m,cpr);
	long long cmp = 0;
	for(long long i = 0;i < n;i++){
		if(i % 2 == 0){
			for(long long j = 0;j < m;j++){
				if(a[cmp].r){
					cout << i+1 << ' '<< j+1;
					return 0;
				}
				cmp++;
			}
		}else{
			for(long long j = m-1;j >= 0;j--){
				if(a[cmp].r){
					cout << i+1 << ' '<< j+1;
					return 0;
				}
				cmp++;
			}
		}
	}
}
