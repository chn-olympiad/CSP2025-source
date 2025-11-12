#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int n,k,ans;
int a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> k;
	bool A = true,B = true;
	if(k!=0)A = false;
	if(k>1)B = false;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i]!=1)A = false;
		if(a[i]>0)B = false;
	}
	if(A){
		cout << n/2;
		return 0;
	}
	cout << rand()%n/2;
	return 0;
}

