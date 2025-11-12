#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int n,k,cnt,a[500005],s[500005];
struct node{int l,r;}c[500005];
void add(int l,int r){cnt++,c[cnt].l=l,c[cnt].r=r;}
bool cmp(node a,node b){return a.r<b.r;}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i=n;i>=0;i--){
		int x=s[i]^k;
		if(mp.count(x)) add(i+1,mp[x]);
		mp[s[i]]=i;
	}
	sort(c+1,c+cnt+1,cmp);
	int now=-2e9,ans=0;
	for(int i=1;i<=cnt;i++){
		if(c[i].l<=now) continue;
		now=c[i].r,ans++;
	}
	cout<<ans;
	return 0; 
}//AKIOI!!!
