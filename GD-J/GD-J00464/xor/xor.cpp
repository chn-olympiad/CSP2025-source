#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000000],cnt;
bool tA = true,tB = true;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
		if(a[i] != 1) tA = false;
		if(a[i] != 1 && a[i] != 0) tB = false;
	}
	if(tA)
	{
		cout << n / 2;
		return 0;
	}
	if(tB)
	{
		int o=0,z=0;
		if(k==1)
		{
			for(int i = 1;i <= n;i ++)
			{
				if(a[i] == 1){
					cnt++;
				}
			}
		}else{
			for(int i = 1;i <= n;i ++)
			{
				if(a[i] == 0){
					cnt++;
				}
			}
		}
		cout<<cnt;
	}else{
		for(int i=1;i<=n;i++){
			if(i==k){
				cnt++;
			}
		}
	}
	return 0;
}
