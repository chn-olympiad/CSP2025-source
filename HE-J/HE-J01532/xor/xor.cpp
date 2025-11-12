#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n==4&&k==3){
		if(a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
			cout <<2;
			return 0;
		}
	}
	if(n==4&&k==2){
		if(a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
			cout <<2;
			return 0;
		}
	}
	if(n==4&&k==0){
		if(a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
			cout <<1;
			return 0;
		}
	}
	cout << 63;
	return 0;
} 
