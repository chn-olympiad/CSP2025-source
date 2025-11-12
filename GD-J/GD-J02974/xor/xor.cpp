#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f;
long long x,y,k,ans=0,t,p[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		for(int i=1;i<=n;i++){
			cin>>x;
			if(x==1) ans++;
		}
		return cout<<ans,0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k) p[i]=1,ans++,x=a[i-1],f=i-2;
		else x=a[i],f=i-1;
		if(p[f]==1) continue;
		for(int j=f;j>=1;j--){
			if(p[j]==1) break;
			x=(x^a[j]);
			if(x==k){
				p[f+1]=1;
				p[j]=1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
