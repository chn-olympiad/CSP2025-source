#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int n,a[N],sum=0;
int maxn =-1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(maxn<a[i]){
			maxn=a[i];
		}
		a[i]+=sum;
	}
	if(sum>2*maxn){
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;
}
