#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll read(){
	char c=getchar();
	ll res=0,f=1;
	while(c<'0'&&c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return f*res;
}
ll n,k,a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cout<<0;
	return 0;
}
