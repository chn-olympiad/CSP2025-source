#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	long int cnt = 0;
	for(int i = 0;i<n;i++){
		int a;
		cin>>a;
		if(a>0){
			cnt++;
		}
	}
	int num1 = 1;
	int num2 = 1;
	for(int i = 0;i<m;i++){
		num1 *=cnt-i;
		num2 *= i+1;
	}
	int xx = num1/num2;
	cout<< xx % 998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

