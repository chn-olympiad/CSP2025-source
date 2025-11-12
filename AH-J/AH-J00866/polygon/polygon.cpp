#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,a[5005],k[5005];
struct node{
	int s,m,ll=0;
};
vector<node> v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	v.push_back(node{a[1],a[1],1});
	v.push_back(node{a[1]+a[2],max(a[1],a[2]),2});
	v.push_back(node{a[2],a[2],1});
	int l=3;
	for (int i=3;i<=n;i++) {
		int tp=l;
		for (int j=0;j<tp;j++) {
			if (((v[j].s+a[i])>2*(max(v[j].m,a[i])))&&(v[j].ll>1)) {
				k[i]++;k[i]%=MOD;
			}
			v.push_back(node{v[j].s+a[i],max(v[j].m,a[i]),v[j].ll+1});
			l++;
		}
		v.push_back(node{a[i],a[i],1});
		l++;
	}
	long long ans=0;
	for (int i=1;i<=n;i++) ans+=k[i],ans%=MOD;
	cout<<ans;
	return 0;
}
