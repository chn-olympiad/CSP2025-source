#include <bits/stdc++.h>
using namespace std;
const long long MAXN= 1e6 + 10;
long long arr[MAXN];
bool cmp(long long x,long long y){
	if(x < y) return x > y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string n;
    cin >> n;
    long long j = 1;
	long long lengt = n.length();
	for(long long i = 0;i < lengt;i++){
		if(n[i] >= '0' && n[i] <= '9'){
			arr[j] = n[i] - 48;
			j ++;
		}
	}
	sort(arr+1,arr+1+j,cmp);
	for(long long i = 1;i < j;i++){
		cout << arr[i];
	}
	
	

	
	
	return 0;
}