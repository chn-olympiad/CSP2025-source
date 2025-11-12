#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
int n,k;
int a[1000100];
int s[1100010];
int maxx=-INF;
int sum=0;
int ans=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) ans++;
		s[i]=s[i-1]^a[i];
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(s[i]==0) sum++;
		}
		cout<<sum;
		return 0;
	}
	cout<<ans;
	return 0;
} 
