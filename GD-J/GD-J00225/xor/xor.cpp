#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,M=2e6+5;
int n,k,cnt,ans,a[N],s[N],t[M],ct[M];
vector<int> v[M];
struct as{
	int l,r;
}d[N];
bool cmp(as a,as b){
	if(a.r==b.r) return a.l<b.l;
	else return a.r<b.r;
}
int erf(int x,int tar){
	int ans=-1,l=1,r=ct[x];
	while(l<=r){
		int mid=(l+r)/2;
		if(v[x][mid-1]>=tar) ans=v[x][mid-1],r=mid-1;
		else l=mid+1;
	}
	return ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		v[s[i]].push_back(i),ct[s[i]]++;
		t[s[i]]=1;
	}
	for(int i=0;i<=n;i++){
		int b=s[i]^k;
		if(!t[b]||erf(b,i+1)==-1) continue;
		d[++cnt].l=i+1;
		d[cnt].r=erf(b,i+1);
	}
	sort(d+1,d+cnt+1,cmp);
	for(int i=1;i<=n;i++){
		int lst=i,flag=0;
		ans++;
		for(int j=i+1;j<=n;j++){
			if(d[j].l>d[i].r){
				flag=1;
				lst=j;
				break;
			}
		}
		if(!flag) break;
		i=lst-1;
	}
	cout<<ans;
}
