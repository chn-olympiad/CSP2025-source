#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int N,M;
long long Ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		Ans=(Ans*i)%mod;
	}
	cout << Ans;
}