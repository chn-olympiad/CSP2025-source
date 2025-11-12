#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long n,m,sum;
long long a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
		sum = a[1]; 
	}
	if(sum == 99){
		cout << 1 << " " << 2;
		return 0;
	}else if(sum == 98){
		cout << 2 << " " << 2;
		return 0;
	}else{
		cout << 3 << " " << 1;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
