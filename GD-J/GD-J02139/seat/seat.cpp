#include<bits/stdc++.h>
using namespace std;

vector<int> a;

bool compare(int c,int d) {
	return c>d; 
}

int xxqz(double e) {
	if(e-floor(e)==0) return e;
	return floor(e)+1;
}

signed main() {
	freopen("seat.in", "w", stdin);
	freopen("seat.in", "seat.out", stdout);
	long long n,m;
	int tmp, r;
	cin>>n>>m;
	
	for(int i=0;i<n*m;i++) {
		cin>>tmp;
		a.push_back(tmp);
	}
	
	r = a[0];
	
	sort(a.begin(), a.end(), compare);


	for(int i=0;i<a.size();i++) {
		if(a[i]==r) {
			tmp = i+1;
			break;
		};
	}
	
	int l=xxqz((double)tmp/n);
	int h=(l%2==0) ? n-(tmp-(l-1)*n)+1 : tmp-(l-1)*n;
	
	std::cout<<l<<' '<<h;
	return 0;
}
