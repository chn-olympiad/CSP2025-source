#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;int t;
struct Peo{
	int s1,s2,s3;
}a[100005];
bool cmp(Peo a,Peo b){
	return a.s1 > b.s1;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i].s1 >>a[i].s2 >> a[i].s3;
		}
		sort(a+1,a+n+1,cmp);
		int sum = 0;
		for(int i = 1;i <= n/2;i++)sum += a[i].s1;
		cout << sum; 
	}
	return 0;
}
