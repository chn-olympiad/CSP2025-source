#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,a[5005],tmp[5005];
int maxx(int l,int r){
	int ma=-1;
	for(int i=l;i<=r;i++)ma=max(ma,a[i]);
	return ma;
}
int sum(int l,int r){
	int s=0;
	for(int i=l;i<=r;i++)s+=a[i];
	return s;
	
}
int Cu(int x,int y){
	int xxx=1,yyy=1,xxyy=1;
	for(int i=1;i<=x;i++)xxx*=i;
	for(int i=1;i<=y;i++)yyy*=i;
	for(int i=1;i<=abs(x-y);i++)xxyy*=i;
	return yyy/(xxx*xxyy);
}
void next_paixu(int cnt){
	for(int i=1;i<n;i++){
		if(cnt==i){
			swap(a[i],a[i+1]);
			return;
		}
	} 
}
int net(int k,int n){
	int ans=0;
	int cnt=1;
	for(int i=1;i<=n*(n-1)-1;i++){
		if(sum(1,k)>maxx(1,k))ans++;
		next_paixu(cnt);
		cnt++;
		if(cnt==n)cnt=1;
		for(int j=1;j<=n;j++)cout<<a[j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		tmp[i]=a[i];
	}
	//cout<<dfs(3,1,0)<<endl;
	int ans=0;
	if(sum(1,n)>maxx(1,n))ans+=3;
	for(int k=3;k<n;k++){
		ans+=net(k,n)%MOD;
		//cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			a[i]=tmp[i];
		}
	}
	cout<<ans/3%MOD<<endl;
	return 0;
}

