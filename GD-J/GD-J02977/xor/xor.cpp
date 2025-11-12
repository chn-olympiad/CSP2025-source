#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010],n,k,pre[200010],l[200010],sum=1,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(l,0x3f,sizeof l);
	for(int i=1;i<=n;i++) cin>>a[i];
	pre[1]=a[1];
	for(int i=2;i<=n;i++) pre[i]=a[i-1]^a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(i==j && i==k){
				l[i]=j;
			}
			if(pre[j]^pre[i-1]==k){
				l[i]=j;
				break;	
			}
		}
		i=l[i]+1; 
	}
	const int M=5*1e5;
	for(int i=1;i<=n;i++){
		if(l[i]<=M) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
