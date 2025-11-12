#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int max=-9999;
	if(s==0)
	{
		cout<<1;
	}
	else
	{
		for(int i=1;i<=s;i++){
		if(a[i]>=max)
		{
			max=a[i];
		}
		}
		cout<<max;
	}
	return 0;
}
