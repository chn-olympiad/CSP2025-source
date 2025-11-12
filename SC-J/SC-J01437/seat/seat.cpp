#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N = 110;

struct Node{
	int p,idx;
};

Node a[N];

bool cmp(Node x,Node y) {
	return x.p > y.p;
}

signed main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i =1;i <= m*n;i++) {
		cin>>a[i].p;
		a[i].idx= i;
	}
	sort(a+1,a+1+n*m,cmp);
	int place = -1;
	int x = 1,y = 1,f= 1;//1:上  2:下
	for(int i = 1;i <= n*m;i++) {
//		cout<<a[i].p<<" "<<i<<" "<<y<<" "<<x<<endl;
		if(a[i].idx == 1) {
			place = i;
			break;
		}
		if(f ==1) {
			if(x < n){
				x++;
			}else{
				y++;
				f=2;
			}
		}else if(f == 2) {
			if(x > 1) {
				x--;
			}else{
				y++;
				f=1;
			}
		}

	}
	cout<<y<<" "<<x;//先列再行
	
	return 0;
}