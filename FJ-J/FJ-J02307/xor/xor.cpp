#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool f=1;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int r=1;
	for(int i=1;i<=n;i+=r){
		r=1;
		int sum=a[i];
		if(sum==k){
			cnt++;
			continue;
		}
		for(int j=i+1;j<=n;j++){
			sum=(sum^a[j]);
			if(sum==k){
				cnt++;
				r=j-i+1;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
