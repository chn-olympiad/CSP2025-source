#include<iostream>
using namespace std;
long long  fact[100005];
const int MOD=998244353;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int x,y;
	cin>>x>>y;
	x=(x)%10000;
	fact[0]=1;
	for(int i=1;i<=100000;i++){
		fact[i]=(fact[i-1]*i)%MOD;
	}
	for(int i=1;i<=y;i++){
	cout<<fact[100000-x];
	}
	return 0;
}
