#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

long long n,m;
int a[105]={0};

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >>m;
	cin >> a[1];
	int idx=1;
	for(int i=2;i<=n*m;i++){
		cin >> a[i];
		if(a[i] > a[1])idx++;
	}
	cout << (idx-1) / n +1 << " ";
	if(((idx-1) / n + 1)&1){
		cout << ((idx-1)%m+1) << endl;
	}else cout << n-((idx-1)%m+1)+1 << endl;
	return 0;
}
