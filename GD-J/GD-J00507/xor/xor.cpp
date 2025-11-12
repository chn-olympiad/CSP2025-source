#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,w[1005][25];
bool check(int x)
{
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],s=0;
		while(x>0){
			w[i][++s]=x%2;
			x/=2;
		}
	}
	if(k<=1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				cnt++;
			}
		}
		cout<<cnt;
	}
	else{
		int l=0,r=n,ans=0;
		while(l<=r){
			int mid=(r+l)/2;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
		cout<<ans;
	}
	return 0;
}
