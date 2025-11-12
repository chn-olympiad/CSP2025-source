#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn] 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int ans=0,sum=0;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		sum^=a[i];
		if (sum==k) ans++,sum=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
