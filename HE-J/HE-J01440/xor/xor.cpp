#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,k,a[N],cnt;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=i;j<=n;j++){
			ans+=a[j];
		}
		if(ans%k==0){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
