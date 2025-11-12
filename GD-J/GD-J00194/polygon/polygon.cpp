#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[5005],n; 
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int sum,maxn,cnt,ans=0,cur;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<(1<<n);i++){
		sum=0;
		maxn=-1e9;
		cnt=0;
		cur=i;
		for(int j=21;j>=0;j--){
			if(cur>=(1<<j)){
				cur-=(1<<j);
				sum+=a[j];
				maxn=max(maxn,a[j]);
				cnt++;
			}
		}
		if(cnt<3)continue;
		if(sum>2*maxn)ans++;
	}
	cout<<ans;
	return 0;
}
