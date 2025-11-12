#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,cnt,ans;
ll a[500005],q[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			q[i]=a[i];
		}
		else{
			q[i]=a[i]^q[i-1];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=cnt;j--)
		{
			int sum=q[i]^q[j];
			if(sum==k){
				ans++;
				cnt=i;
				break;	
			}
		}
	}
	cout<<ans;
	return 0;
}
