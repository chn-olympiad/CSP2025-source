#include <bits/stdc++.h> 
using namespace std;
struct mon{
	long long id,d,b,c;
} a[100005];
bool cmp(mon x,mon y){
	return x.d>y.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t;cin >> t;
	while(t--){
		long long n;cin >> n;
		long long ab=0,bb=0,cb=0,zh=0;
		for(long long i = 1 ; i <= n ; i++){
			cin >> a[i].d >> a[i].b >> a[i].c;
		}
		sort(a+1,a+n+1,cmp);
		cout << a[1].d+a[2].d;
	}
	
	return 0;
}