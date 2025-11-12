#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000];
long long h,id;
bool cmp(long long a,long long b){
	return a>b;
}
int x=1,y=1;
bool f=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	h=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==h)id=i;
	}
	for(int i=1;i<=n*m;i++){
		if(i==id){
			cout << y << ' ' << x;
			return 0;
		}
		if(f)x++;
		else x--;
		if(x<=0){
			x=1;
			y++;
			f=1;
		}else if(x>n){
			x=n;
			y++;
			f=0;
		}
	}
	return 0;
}
