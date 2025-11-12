#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int s[500005];
vector<int>mp[1100005];
struct node{
	int x,y;
}t[500005];
int id=0;
int check(int p,int c){
	int l=0,r=mp[p].size()-1,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(mp[p][mid]>c)r=mid-1;
		if(mp[p][mid]==c)return c;
		if(mp[p][mid]<c)l=mid+1;
	}
	return mp[p][l];
}
bool cmp(node g,node h){
	if(g.y!=h.y)return g.y<h.y;
	return g.x<h.x;
}
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		mp[s[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		 int d=s[i-1]^k;
		 if(!mp[d].empty() && mp[d][mp[d].size()-1]>=i){
			 t[++id].x=i;
			 t[id].y=check(d,i);
		 }
	}
	sort(t+1,t+id+1,cmp);
	int last=0;
	for(int i=1;i<=id;i++){
		if(t[i].x>last)ans++,last=t[i].y;
	}
	cout<<ans<<'\n';
	return 0;
}
