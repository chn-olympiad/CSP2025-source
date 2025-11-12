#include<bits/stdc++.h>

using namespace std;
const int N=5e5+5;
#define ll long long

ll n,k,a[N],cnt,ans,flag=1,flag2=1;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(!((a[i]==0||a[i]==1)&&flag==1)) flag=0;
		if(!(a[i]==1&&flag2==1)) flag2=0;
	}
	if(flag2) {
		cout<<n/2;
		return 0;
	}
	else if(flag) {
		if(k==1) for(int i=1;i<=n;i++) ans+=(a[i]==1);
		else for(int i=1;i<=n;i++) ans+=(a[i]==0);
		cout<<ans;
		return 0;
	}
	cnt=0;
	for(int i=1;i<=n;i++) {
		cnt^=a[i];
		if(cnt==k) ans++,cnt=0;
	}
	cout<<ans;
	return 0;
}
