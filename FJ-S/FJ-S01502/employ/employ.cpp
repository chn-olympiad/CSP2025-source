#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int pc(int x){
	if(x==1) return 1;
	return pc(x-1)*x;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	cout<<pc(n);
	return 0;
}
