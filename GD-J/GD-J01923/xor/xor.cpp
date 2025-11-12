#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,flag,sum;
long long a[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0)flag=1;
		if(a[i]==1)sum++;a[i]^=a[i-1];
	}
	int s=1;
	if(!flag&&k==1){
		cout<<sum;
		return 0; 
	}
	for(int i=1;i<=n;i++){
		for(int j=s;j<=i;j++){
			if((int)(a[i]^a[j-1])==k){
				ans++;
				s=i+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
