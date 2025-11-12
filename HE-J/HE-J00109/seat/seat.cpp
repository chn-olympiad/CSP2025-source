#include <bits/stdc++.h>
using namespace std;
int a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,cnt;
	cin >> n >> m;
	for(int i=1;i<=n*m;++i){
		cin >> a[i];
	}
	int box=a[1];
	for(int i=1;i<=n*m;++i){
    	for(int j=i+1;j<=n*m;++j){
    		if(a[i]<a[j]){
    			swap(a[i],a[j]);
			}
		}
	}
	for(int i=1;i<=n*m;++i){
		if(a[i]==box){
			cnt=i;
			break;
		}
	}
	if(cnt<=n){
		cout << 1 << ' ' << cnt;
	}else{
		cout << cnt/n+1 << ' ';
		if((cnt/n+1)%2==0){
			cout << n-cnt%n+1;
		}
		else{
			cout << cnt%n;
		}
	}
    return 0;
}
