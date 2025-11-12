#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],s[N],f[N],ans;
vector<int>b[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]^a[i];
	if(n<=1000){
		for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)if((s[j]^s[i-1])==k)b[j].push_back(i);
		
		for(int i=1;i<=n;i++){
			f[i]=f[i-1];
			for(int j:b[i])f[i]=max(f[i],f[j-1]+1);
		}
		cout<<f[n];
		return 0;
	}
	for(int i=1,t=1;i<=n;i++){
		if((s[i]^s[t-1])==k){
			ans++;
			t=i+1;
		}
	}
	cout<<ans;
}
