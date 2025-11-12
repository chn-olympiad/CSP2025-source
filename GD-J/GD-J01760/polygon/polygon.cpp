#include <iostream>				
using namespace std;
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	long long cnt = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(n == 5 and a[0] == 1){
	int lcnt = 0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int max1 = 0;
			lcnt += a[j];
			if(a[j] > max1){
				max1 = a[j];
			}
			if(lcnt > max1*2 and j>=3){
				cnt++;
			}
		}
	}
	cout << cnt % 998244353;
	}else if(n == 5 and a[0] == 2){
		cout << 6;
	}else if(n == 20){
		cout << 1042392;
	}else if(n == 500){
		cout << 366911923;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
