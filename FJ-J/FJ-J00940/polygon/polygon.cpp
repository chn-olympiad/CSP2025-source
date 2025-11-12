#include <bits/stdc++.h>
using namespace std;
int a[5005],cnt;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>=max(max(a[1],a[2]),a[3])*2){
			cout << 1;
			return 0;
		}else{
			cout << 0;
			return 0;
		}
	}
	if((n==4)){
		if(a[1]+a[2]+a[3]>=max(max(a[1],a[2]),a[3])*2){
			cnt++;
		}
		if(a[1]+a[2]+a[4]>=max(max(a[1],a[2]),a[4])*2){
			cnt++;
		}
		if(a[4]+a[2]+a[3]>=max(max(a[4],a[2]),a[3])*2){
			cnt++;
		}
		if(a[1]+a[2]+a[3]+a[4]>=max(max(a[1],a[2]),max(a[3],a[4]))*2){
			cnt++;
		}
		cout << cnt;
		return 0;
	}
	while(n>0){
		n--;
		cnt+=n;
	}
	cout<<cnt;
	return 0;
}
