#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
struct node{
	int l,r;
	bool operator<(const node a)const{
		return r!=a.r?r<a.r:l<a.l;
	}
};
int n,k,cnt=0,a[N],s[N],ans=0;
vector<node>g;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]^s[i-1];
	}
	for(int i=1;i<=n;i++)
		for(int j=i-1;j>=0;j--)
			if((s[i]^s[j])==k){
				g.push_back(node{j+1,i});
				cnt++;
				break;
			}
	sort(g.begin(),g.end());
	int kr=0;
	for(int i=0;i<cnt;i++)
		if(g[i].l>kr) ans++,kr=g[i].r;
	cout<<ans;
	return 0;
}
