#include <iostream>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n >> m; 
	
	long long cnt = 0;
	long long c;
	cin >> c;
	
	long long cnt_run = n*m - 1;
	while(cnt_run--){
		long long t;
		cin >> t;
		if(t > c){
			cnt++;
		}
	}
	
	cnt++;
	
	long long first;
	first = (cnt + n - 1) / n;
	cout<< first << " ";
	
	if(first % 2 == 1){
		long long how_l = (cnt + n - 1) / n;
		how_l--;
		cout<< cnt - how_l* n;
	}
	else{
		cout<<n - cnt % n + 1;
	}
	return 0;
}

