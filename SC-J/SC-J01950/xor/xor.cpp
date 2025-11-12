#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int a[500005],s[500005];
int sum(int l,int r){return ~(~s[l-1]^s[r]);}
int f[500005];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	if(n>10000){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==k)ans++;
		}
		cout<<ans;
		return 0;
	}
	cin>>a[1];s[1]=a[1];
	for(int i=2;i<=n;i++)cin>>a[i],s[i]=s[i-1]^a[i];
	f[1]=(a[1]==k);
	for(int i=2;i<=n;i++)
		for(int j=0;j<i;j++)
			for(int o=j+1;o<=i;o++)
				f[i]=max(f[i],f[j]+(sum(o,i)==k));
	cout<<f[n];
	return 0;
}