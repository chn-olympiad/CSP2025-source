#include <bits/stdc++.h>
using namespace std;

long long n,k;
long long a[600000];
bool b[600000]={false};
long long cnt =0;
long long temp;

void mark(long long l, long long r){
	for (long long i = l ; i <= r; i ++ ){
		b[i]=true;	
	}
	return;
}

//bool contains(long long l,long long r){
//	for (long long i = l; i <= r ; i ++ ){
//		if (b[i]) return true;
//	}
//	return false;
//}

bool check(long long l,long long r){
	temp = a[l];
	if (b[l] || b[r]) return false;
	for (long long i = l+1 ; i <= r ; i ++ ){
		if (b[i]) return false;
		temp^=a[i];
	}
	return temp == k;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (long long i = 1 ; i <= n ;i ++ ){
		cin >> a[i];
	}
	for (long long i = 0; i <= n ; i ++ ){
		for (long long j = 1; j+i <= n; j++){
			if (b[j] || b[j+i]) continue;
		//	cout << j << " " << j+i << endl;
			if(check(j,j+i)){
			//	cout << j << " " << j+i << endl;
				mark(j,j+i);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
