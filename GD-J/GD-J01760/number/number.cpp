#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","r",stdout);
	string n;
	cin >> n;
	int len = n.length();
	int cnt = 0;
	for(int i=0;i<len;i++){
		if(n[i] >= '0' and n[i] <= '9'){
			a[cnt] = int(n[i]) - 48;
			cnt++;
		}
	}
	sort(a,a+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
