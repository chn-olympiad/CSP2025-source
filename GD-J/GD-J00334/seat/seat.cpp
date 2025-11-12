//2025 CSP-J t2 seat.cpp  by ACGO - Dark_eve
#include<bits/stdc++.h>
using namespace std;

int n,m,a1,tmp;
vector<int>a;
int c,r;

bool cmp(int a,int b){
	return a > b;
}

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m;
	
	cin>> a1;
	a.push_back(a1);
	
	for(int i = 1;i < (n * m);i++){
		cin >> tmp;
		a.push_back(tmp);
	}
	
	sort(a.begin(),a.end(),cmp);
	auto seat = find(a.begin(),a.end(),a1);
	tmp = seat - a.begin() + 1;
	
	//cout << tmp;			//debug
	c = tmp / n;
	r = tmp % n;
	if((c % 2) == 1){
		r = n - r + 1;
		if(tmp == a.size()) r--;
	}   
	if((tmp % n) != 0) c++;
	
	cout << c << " " << r;
	
	return 0;
}
