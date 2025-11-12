#include<bits/stdc++.h>
using namespace std;
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,m=1;cin.tie(0)->sync_with_stdio(false);
	cin>>a>>b;
	int h[a+1];
	for(int i=1;i<=a;i++)cin>>h[i];
	for(int i=1;i<=a;i++)
	{int o=0;
	for(int p=i;p>=m;p--)
	{o^=h[p];if(o==b){++ans;m=i+1;break;}}
	}
	cout<<ans;
	return 0;
}
