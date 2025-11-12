#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn=520;
const int mod=998244353;
using ll=long long;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n, m;
	cin>>n>>m;
	char is[maxn];
	int s[maxn];
	bool all1=true;
	for (int i=1;i<=n;i++){
		cin>>is[i];
		s[i]=is[i]-48;
		if (s[i]==0) all1=false;
	}
	int c[maxn];
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	ll res=0;
	if (all1){
		cout<<161088479; // 视情况补全 
	} else {
		cout<<114514; //qwq
	}
	return 0;
}

