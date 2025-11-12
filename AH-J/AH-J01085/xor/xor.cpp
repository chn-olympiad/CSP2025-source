#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt0,cnt1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) cnt0++;
		if(a[i]==1) cnt1++;
	}
	if(k==0){
		if(cnt0==0&&cnt1) cout<<n/2;
		if(cnt0&&cnt1){
			long long cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) cnt++;
				else{
					cnt1+=cnt/2;
					cnt=0;
				}
			}
			cout<<cnt0+cnt1;
		}
		if(cnt0&&cnt1==0) cout<<n;
	}
	else if(k==1){
		if(cnt0==0&&cnt1) cout<<n;
		else if(cnt0&&cnt1) cout<<cnt1;
		else if(cnt0&&cnt1==0) cout<<0;
	}
	return 0;
}
