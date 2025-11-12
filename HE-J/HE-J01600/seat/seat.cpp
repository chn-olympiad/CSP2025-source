#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,a,ans,cnt = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>a;
		if(i == 1){
			ans = a;
		}
		if(a > ans){
			cnt++;
		}
	}
	if(n == 1 && m == 1){
		c = 1;
		r = 1;
		cout<<c<<" "<<r;
		return 0;
	}
	if(n == 1 && m <= 10){
		r = 1;
		c = cnt;
		cout<<c<<" "<<r;
		return 0;
	}
	if(m == 1 && n <= 10){
		c = 1;
		r = cnt;
	}
	if(n == 2 && m == 2 && cnt > n){
		c = 2;
		r = 2;
		cout<<c<<" "<<r;
		return 0;
	}
	if(n == 2 && m <= 10 && cnt <= n){
		c = 1;
		r = cnt;
		cout<<c<<" "<<r;
		return 0;
	}
	if(n == 2 && m <= 10 && cnt >= n){
		for(int i = 2;i <= m;i++){
			if(cnt <= i*n && cnt - i*n == 1){
				c = i;
				r = 2;
			}else if(cnt <= i*n && cnt - i * n == 0){
				c = i;
				r = 1;
			}
		}
		cout<<c<<" "<<r;
		return 0;
	}
	if(n <= 10 && m == 2){
		if(cnt < n){
			c = 1;
			r = cnt;
		}else if(cnt >n){
			c = 2;
			r = n-(cnt - n)+1;
		}
		cout<<c<<" "<<r;
		return 0;
	}
	if(n <= 10 && m <= 10){
		if(cnt < n){
			c = 1;
			r = cnt;
		}
		for(int i = 2;i <= n;i++){
			if(cnt <= i*n && i % 2 == 0){
				c = i;
				r = n- (cnt - n) + 1;
				break;
			}else if(cnt <= i*n && i % 2 == 1){
				c = i;
				r = i*n - cnt -1;
				break;
			}
		}
		cout<<c<<" "<<r;
		return 0;
	}
	return 0;
}
