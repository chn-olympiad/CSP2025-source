#include<bits/stdc++.h>
#define _all(i,a,b) for(int i = a; i <= b; i++)
#define __all(i,a,b) for(int i = a; i < b; i++)
#define r_all(i,a,b) for(int i = a; i >= b;i--)
#define vt vector<int>
#define v2 vector<vt>
#define vl vector<LL>
using namespace std;
using LL = long long;
struct student{
	int x,pos;
	bool operator<(const student & other) {
		return x > other.x; 
	}
};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int n = 1,m = 1;
	cin>>n>>m;
	vector<student> a(n*m + 5);
	__all(i,0,n*m) cin>>a[i].x,a[i].pos = i + 1;
	sort(a.begin(),a.begin() + (n * m - 1));
	int cnt = 0;
	_all(i,1,m){
		if(i % 2){
			_all(j,1,n) if(a[cnt++].pos == 1) return printf("%d %d",i,j),0;
		} else r_all(j,n,1) if(a[cnt++].pos == 1) return printf("%d %d",i,j),0;
	}
	return 0; //freopen!
}
//freopen!

