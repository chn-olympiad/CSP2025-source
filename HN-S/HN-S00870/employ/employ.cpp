#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long h=1;
	for(int i=100;i>=100-m;i--){
		h*=i;
		h=h%998244353;
	}
	cout<<h;
}
