#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,R,siz;
int a[105];
int ans1,ans2;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	siz = n * m;
	for(int i = 1;i <= siz;i++){
		cin>>a[i];
		if(i == 1){
			R = a[i];
		}
	}
	sort(a + 1,a + siz + 1);
	int seat = lower_bound(a + 1,a + siz + 1,R) - (a);
	
	double c = ceil(siz * 1.0 / 2);
	if(siz % 2 == 1){	
		seat = 2 * c - seat;
	}else{
		c += 0.5;
		seat = 2 * c - seat;
	}
	ans1 = ceil(seat * 1.0 / n);
	int q = seat % n;
	if(q == 0) q = n;
	if(ans1 % 2 == 1){
		ans2 = q;
	}else{
		double c = ceil(n * 1.0 / 2);
		if(siz % 2 == 1){
			q = 2 * c - q;
		}else{
			c += 0.5;
			q = 2 * c - q;  
		}
		ans2 = q;
	}
	cout<<ans1<<' '<<ans2<<endl;
	return 0;
}

