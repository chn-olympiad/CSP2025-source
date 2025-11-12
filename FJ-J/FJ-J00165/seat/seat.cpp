#include <bits/stdc++.h>
using namespace std;
long long n,m;
int b = 0;
int cnt = 0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seatout","r",stdout);
	cin >> n >> m;
	long long r = n*m;
	vector<int>a(r);
	for(int i=0;i<r;i++){
		cin >> a[i];
	}
	long long s = a[0];
	sort(a.begin(),a.end());
	int l = 0,h = 0;
	for(int k=0;k<r;k++){
		if(k==0){		
			l++;
		}
		h++;
		if(h>m){
			h = 1;
			l++;
		}
		if(a[k] = s && cnt == 0){
			cout << l << " " << h;
			cnt++;
		}
	}
	return 0;
}
