#include<iostream>
#include<algorithm>
using namespace std;

int r,c,n,m,pts,a[114];

bool cmp(int a,int b){
	return a > b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> r >> c >> pts;a[1] = pts;
	for(int i = 2;i <= r*c;++i) cin >> a[i];
	sort(a+1,a+r*c+1,cmp);
	for(int i = 1;i <= r*c;++i)
		if(a[i] == pts){pts = i;break;}
	n = (pts-1)/r + 1;m = pts % r;
	if(!m) m = r;
	if(!(n & 1)) m = r-m+1;
	cout << n << " " << m;
	return 0;
}
