#include<bits/stdc++.h>
using namespace std;

long long T,n,m,x,y,z,ans;

struct node{
	long long v1,v2,t1,t2,t3,x;
}a[100050];

bool cmp(node a,node b){
	return a.v1 > b.v1;
}
 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		ans = 0;
		for(long long i = 1;i <= n;i ++){
			cin >> a[i].t1 >> a[i].t2 >> a[i].t3;
			a[i].t2 *= 2;
			a[i].v1 = a[i].t2 - a[i].t1;
		}
		sort(a + 1,a + 1 + n,cmp);
		m = n / 2;
		for(long long i = 1;i <= m;i ++){
			ans += a[i].t2;
		}
		for(long long i = n;i > m;i --){
			ans += a[i].t1;
		}
		cout << ans << endl;
	}
	return 0;
}
