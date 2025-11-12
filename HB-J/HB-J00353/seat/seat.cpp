#include <bits/stdc++.h>
using namespace std;
const int N = 150;
int n,m,a[N],val,ind;
bool cmp(int a,int b){return a > b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++){
		cin >> a[i];
		if(i == 1) val = a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++)
		if(a[i] == val){
			ind = i;
			break;
		}
	int tmp = (ind/n);
	if(ind % n == 0){
		if(tmp & 1) cout << tmp << ' ' << n;
		else if(tmp % 2 == 0) cout << tmp << ' ' << 1;
		return 0;
	}
	if(tmp & 1) cout << tmp+1 << ' ' << n+1-(ind%n);
	else if(tmp % 2 == 0) cout << tmp+1 << ' ' << ind%n;
	return 0;
}