#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005],ans=0,cur=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		if(x==k)ans++;
		else a[++cur]=x;
	}
	cout << ans;
	return 0;
}//"^"是异或，只能用于变量 