#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum = 0;
	scanf("%d%d",&n,&k);
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i] == k)
		{
			sum++;
		}
	}
	cout<<max(1,sum)<<endl;
	return 0;
}
