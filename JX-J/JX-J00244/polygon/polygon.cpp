#include<bits/stdc++.h>
using namespace std;
const int M=998244353,N=1e4;
int ans,n,a[N],cnt,s[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	if(n==3){
		if(s[n]>2*max(a[1],max(a[2],a[3])))ans++;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int maxn=0;
		for(int j=i+1;j<=n;j++){
			maxn=max(a[j],maxn);
			if(j-i+1<3)continue;
			else if(s[j]-s[i-1]>2*maxn)ans++;
		}
	}
	cout<<ans;
	return 0;
}
