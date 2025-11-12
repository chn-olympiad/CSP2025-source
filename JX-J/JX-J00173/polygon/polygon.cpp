#include <bits/stdc++.h>
using namespace std;

int n,cnt=0;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int maxx=max(a[1],max(a[2],a[3]));
	if((a[1]+a[2]+a[3])>2*maxx) cnt++;
	cout << cnt;


	return 0;
}
