#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[500050],ans,o;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool f = true;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i ++){
		scanf("%lld",&a[i]);
		if(a[i]==0)o++;
		if(a[i]==1)ans++;
	}
	if(k == 0 && o == 0){
		cout<<n/2;
		return 0;
	}
	if(k == 1){
		cout<<ans;
		return 0; 
	}
	ans=0;
	for(int i = 1;i <= n;i ++)
	{
		if(a[i] == 0){
			ans++;
			continue;
		}
		if(a[i] == a[i+1] && a[i]==1){
			a[i] = 0;a[i+1]=0;
			ans++;i++;
		}
	}
	cout<<ans;
	return 0;
}
