#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
ll n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	ll m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)m++;
	}cout<<m;
	//buhui
	fclose(stdin);
	fclose(stdout);
	return 0;
}

