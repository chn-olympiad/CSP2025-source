#include <bits/stdc++.h>
using namespace std;
int n,m,r,s,h,l,sum;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n * m;i++){
		cin >> a[i];
	}
	r = a[0];
	for(int i = 0;i < n * m;i++){
		if(a[i] < a[i + 1]){
			swap(a[i],a[i + 1]);
		}
	}
	for(int i = 0;i < n * m;i++){
		if(a[i] == r){
			s = i + 1;
		}
	}
	if(s % n != 0){
		l = s / n + 1;
	}
	else{
		l = s / n;
	}
	if(l % 2 == 0){
		if(s % n == 0){
			h = 1;
		}
		else{
			sum = s % n;
			h = n - sum + 1;
		}
	}
	else{
		if(s % n == 0){
			h = n;
		}
		else{
			h = s % n;
		}
	}
	cout << l << " " << h;
	return 0;
}
