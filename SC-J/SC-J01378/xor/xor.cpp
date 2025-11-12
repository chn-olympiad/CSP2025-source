#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
long long a[MAXN],s[MAXN],n,k,tmp=0;
struct node{
	int l,r;
};
node mp[MAXN];
bool cmp(node x,node y){
	return x.r<y.r;
}
map<long long,int> MP;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=(s[i-1]^a[i]);
		if(s[i]==k) mp[tmp++]={1,i};
		int xr=(s[i]^k);
		if(MP[xr]){
			mp[tmp++]={MP[xr]+1,i};
		} 
		MP[s[i]]=i;
	}
	sort(mp,mp+tmp-1,cmp);
	long long ans=0,t=0;
	for(int i=0;i<tmp;i++){
		if(mp[i].l>t){
			ans++;
			t=mp[i].r;
		}
	}
	cout<<ans;
	return 0;
}
