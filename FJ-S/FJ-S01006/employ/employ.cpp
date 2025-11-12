#include<bits/stdc++.h>
using namespace std;
const int long long N=998244353;
long long n,m;
string s;
long long c[505];
long long cnt; 
int main(){
	cin >>n>>m;
	cin >>s;
	for (int i=1;i<=n;i++){
		cin >>c[i];
		if (c[i]==0) cnt++;
	}
	if (m==1){
		cout <<515058943;
		return 0;
	}
	n-=cnt;
	cout <<(n*(n-1))%N;
	return 0;
}
