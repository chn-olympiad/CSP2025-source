#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010];
long long x[1010][1010];
bool cmp(long long a,long long b){return a > b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)cin >> a[i];
	long long cspj_daa = a[1];
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= m;i++){
		if(i % 2 == 1){
			long long start = (i - 1) * n;
			for(int j = 1;j <= n;j++){
				x[j][i] = a[start + j];
			}
		}else{
			long long start = i * n + 1;
			for(int j = n;j >= 1;j--){
				x[j][i] = a[start - j];
			}
		}
	}
	/*
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
	*/
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(x[i][j] == cspj_daa){
				cout << j << " " << i << endl;
				return 0;
			}
		}
	}
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	cout << "You have no egg!!!" << endl;
	return 0;
}
