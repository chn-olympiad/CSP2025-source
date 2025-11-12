#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int ans=0,maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
		maxn=max(maxn,a[i]);
	}
	if(maxn*2<ans){
		cout<<1<<endl;
	}else cout<<0<<endl;

	return 0;
}
