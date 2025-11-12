#include<bits/stdc++.h>
using namespace std;
int a[5010],n;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i = 1;i<=n;i++) cin >>a[i];
	sort(a+1,a+n+1);
	int m = 3;
	while(m<n){
		int cnt = 0;
		for(int i = l;i<=r;i++){
			cnt+=a[i];
		}
		if(cnt>a[r]*2){
			ans++;
		}
		r++;
		if(r>n){
			l++;
			r = l+2;
		}
	}
	cout <<ans;
	return 0;
}

