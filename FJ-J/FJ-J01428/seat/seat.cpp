#include <bits/stdc++.h>
//#define int long long
//#define db double
using namespace std;
int n,m;

struct data{
	int num,id;
}arr[105];

bool cmp(const data x,const data y){
	return x.num>y.num;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++) cin >> arr[i].num,arr[i].id=i;
	sort(arr+1,arr+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(arr[i].id==1){
			cout << (i+n-1)/n <<" ";
			if(((i+n-1)/n)&1) cout << (i%n!=0 ? i%n : n);
			else cout << (n-i%n+1!=n+1 ? n-i%n+1 : 1);
			return 0;
		}
	}
	return 0;
}
