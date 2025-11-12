#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int a[N],sum[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int ans=0,l=1,r=1,flag=0;
	while(r<=n){
		flag=0;
		for(int i=l;i<=r;i++){
			if((sum[r]^sum[i-1])==k){
				ans++;
				l=++r,flag=1;;
				break;
			}
		}
		if(!flag)r++;
	}
	cout<<ans;
	return 0;
}
