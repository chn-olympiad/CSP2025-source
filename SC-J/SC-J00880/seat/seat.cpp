#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 110;
int n,m,A,Bigger,arr[N],mp[N][N];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin >> n >> m >> A;arr[1] = A;
	for(int i = 2;i <= n*m;++i) cin >> arr[i];
	sort(arr+1,arr+1+n*m,[&](int a,int b){return a > b;});
	for(int i = 1,j = 1,k = 1;i <= n*m;++i){
		mp[j][k] = arr[i];
		if(arr[i] == A){
			cout << k << " " << j << "\n";
			return 0;
		}if(k&1){
			if(j == n) ++k;
			else ++j;
		}else{
			if(j == 1) ++k;
			else --j;
		}
	}cout << "I Love Furina Forever.\n";
	return 0;
}