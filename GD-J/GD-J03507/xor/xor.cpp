#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n,k,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	bool flag = true;//A性质 
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			flag = false;
			break;
		}
	}
	if(flag){
		cout << n / 2;
		return 0;
	}
	bool ff = true;//B性质
	for(int i=1;i<=n;i++){
		if(a[i]>1){
			ff = false;
			break;
		}
	}
	if(ff){
		if(k==1){
			int cnt = 0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) cnt++;
			}
			cout << cnt;
		}
		else{
			int one = 0,zero = 0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) one++;
				else zero++;
			}
			cout << one / 2 + zero;
		}
	}


	return 0;
}

