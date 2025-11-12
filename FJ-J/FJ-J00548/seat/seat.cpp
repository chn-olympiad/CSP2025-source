#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n,m,a,cnt=1;
bool flag;

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> a;
	for(int i=1;i<n*m;i++){
		int b;
		cin >> b;
		if(b > a)cnt++;
	}
	for(int i=1;i<=m;i++){
		if(flag){
			for(int j=n;j>=1;j--){
				cnt--;
				if(!cnt){
					cout << i << " " << j;
					return 0;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				cnt--;
				if(!cnt){
					cout << i << " " << j;
					return 0;
				}
			}			
		}		
		flag ^= 1;
	}
	return 0;
}
