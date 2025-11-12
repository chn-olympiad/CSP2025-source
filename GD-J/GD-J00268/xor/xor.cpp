#include<bits/stdc++.h>
using namespace std;
int a[500010];
int sum[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int lst=0,ans=0;
	for(int i=1;i<=n;i++){
		int ss=0;
		for(int j=i;j>lst;j--)
		{
			ss^=a[j];
			if(ss==k){
				lst=i;
				ans++;
				break;
			}
//			if(sum[i]^sum[j-1]==k){
//				lst=i;
//				ans++;
//				break;
//			}
		}
	}
	cout<<ans;
	return 0;
}
