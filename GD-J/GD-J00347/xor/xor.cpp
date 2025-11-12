#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int M=5e5+5;
vector<int> mp[N+M];
struct T{
	int l,r;
} s;
vector<T> a;
int n,k,sum[M],b[M],vis[M],ans;
int erfen(int x,int i){
	int l=0,r=mp[x].size()-1,ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(mp[x][mid]<i) ans=mp[x][mid]+1,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0].push_back(0);
	for(int i=1;i<=n;++i){
		cin>>b[i];
		sum[i]=sum[i-1]^b[i];
		mp[sum[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		int x=sum[i]^k;
		int y=-1;
		y=erfen(x,i);
		if(y!=-1){
			s.l=y;
			s.r=i;
			a.push_back(s);
		}
	}
	n=a.size();
	for(int i=0;i<n;++i){
		bool flag=false;
		for(int j=a[i].l;j<=a[i].r;++j){
			if(vis[j]){
				flag=true;
				break;
			}
		}
		if(flag) continue;
		ans++;
		for(int j=a[i].l;j<=a[i].r;++j) vis[j]=1;
	}
	cout<<ans;
	return 0;
}
