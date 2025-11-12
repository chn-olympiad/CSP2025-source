#include <iostream>
#include <cstdio>
using namespace std;
const int Maxn=998244353;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	int c_num=0;
	for (int i=1;i<=n;i++){
		cin >> c[i];
		if (c[i]==0) c_num++;
	}
	long long ans=1;
	for (int i=2;i<=n;i++){
		ans=(ans*i)%Maxn;
	}
	cout << ans;
}