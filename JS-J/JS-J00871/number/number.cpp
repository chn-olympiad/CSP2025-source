#include <bits/stdc++.h>
using namespace std;
// Li Hao Ming JS-J00871 C402-034
string readin,s;
bool f[1000020];
int sum,a[1000020];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> readin;
	int len = readin.length();
	for(int i = 0;i < len;i++){
		if(readin[i] >= '0' && readin[i] <= '9'){
			a[i+1] = readin[i] - '0';
			sum++;
		}
	}
	sort(a+1,a+len+1,greater<int>());
	for(int i = 1;i <= sum;i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
