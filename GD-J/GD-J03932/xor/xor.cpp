#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
const int N=5e5+8;
int n,k,ans,maxx;
long long a[N],sum[N];
struct ran{
	int l,r;
};
vector<ran>v;
bool cmp(ran &a,ran &b){
	if(a.l==b.l)
		return a.r<b.r;
	return a.l<b.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k){
				v.push_back({i,j});
				break;
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		if(v[i].r<=maxx){
			maxx=v[i].r;
		}
		else if(v[i].l>maxx){
			ans++;
			maxx=v[i].r;
		}
	}
	cout<<ans;
	return 0;
}
