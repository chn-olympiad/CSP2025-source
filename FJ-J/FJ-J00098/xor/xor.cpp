#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=-1;
	for(int i=1;i<=n&&n-i+1>ans;i++){
		int left=i,right=i;
		int sum=0,cnt=0;
		while(right<=n){
			sum^=a[right];
			right++;
			if(sum==k){
				cnt++;
				sum=0;
				left=right;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
