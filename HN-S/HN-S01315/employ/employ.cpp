#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
	}
	unsigned long long a=1,b=1;
	for(int i=1;i<=m;i++){
		a*=i;
	}
	int k=n;
	for(int i=1;i<=m;i++){
		b*=k;
		k--;
	}
	cout<<b/a%Mod<<endl;
	return 0;
}

