#include<bits/stdc++.h>
using namespace std;
const int INF=0x7f7f7f7f;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=INF,ans=0,a;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(cnt==INF)cnt=a;
		else cnt=(cnt^a);
		if(cnt==k)ans++,cnt=INF;
	}
	cout<<ans;
	return 0;
}//wxjwxjwxjwxj
