#include<bits/stdc++.h>
using namespace std;
struct node{
	map<int ,int> mp;
	int sum;
	int ans;
	int id;
}a[10005];
bool cmp(node a,node b){
	return a.ans<b.ans;
}
int f[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)a[i].id=i;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].mp[v]=w;
        a[v].mp[u]=w;
        a[u].sum+=w;
        a[v].sum+=w;
        a[u].ans+=v;
        a[v].ans+=u;
    }
    sort(a+1,a+n+1,cmp);
    if(k==0){
		int ans1=0;
		map<int ,int> mp1;
		for(int i=1;i<=n;i++){
			for(auto it=a[i].mp.begin();it!=a[i].mp.end();it++){
				if(mp1[it->first])continue;
				else ans1+=it->second;
			}
			mp1[a[i].id]=1;
		}
		cout<<ans1;
		return 0;
	}
    int ans1=0;
    int dl=0;
    map<int ,int> mp1;
    for(int i=1;i<=k;i++){
		cin>>f[i];
		for(int i=1;i<n;i++){
			int x;
			cin>>x;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i].ans==n*(n+1)/2-dl-a[i].id){
			if(f[i]<=a[i].sum){
				ans1+=f[i];
			}
			else {
				for(auto it=a[i].mp.begin();it!=a[i].mp.end();it++){
					if(mp1[it->first])continue;
					else ans1+=it->second;
				}
			}
			dl+=a[i].id;
			mp1[a[i].id]=1;
		}
		else {
			ans1+=f[i];
			dl+=a[i].id;
			mp1[a[i].id]=1;
		}
	}
	cout<<ans1;
    return 0;
}
