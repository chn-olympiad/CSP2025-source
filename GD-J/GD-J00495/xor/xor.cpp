#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,ans;
int sum[500005];
struct node{
	int l,r;
}f[500005];
bool cmp(node q1,node q2){
	if(q1.r==q2.r){
		return q1.l<q2.l;
	}
	return q1.r<q2.r;
}
vector<int> h[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1 ; i <= n ; ++i){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i]; 
		h[sum[i]].push_back(i);
	}
	int cur=k;
	for(int p = 1 ; p <= n ; ++p){
		f[p].l=p; 
		cur=k^sum[p-1];
		if(h[cur].size()>0){
			auto tmp=lower_bound(h[cur].begin(),h[cur].end(),p);
			if(tmp==h[cur].end())
				f[p].r=10000000;
			else
				f[p].r=*tmp;
		}
		else f[p].r=10000000;
	}
//	for(int i = 1 ; i <= n ; ++i){
//		cout<<f[i].r<<" "; 
//	}	
//	cout<<endl;
	sort(f+1,f+n+1,cmp);
	int rig=0,ans=0;
	for(int i = 1 ; i <= n ; ++i){
		if(f[i].r==10000000)
			break;
		if(f[i].l>rig){
			rig=f[i].r;
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}
