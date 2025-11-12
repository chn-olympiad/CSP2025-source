#include<bits/stdc++.h>
using namespace std;
struct range{
	int l,r;
	bool operator<(const range &a)const{
		if(r!=a.r) return r<a.r;
		return l>a.l;
	}
}ran[500005];
int n,k,cnt,a[500005],s[500005];
map<int,vector<int> > m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		m[s[i]].push_back(i);
	}
	int l,r,mid,ans,sum;
	for(int i=1;i<=n;i++){
		sum=k^s[i-1];
		l=0;
		r=m[sum].size()-1;
		ans=-1;
		while(l<=r){
			mid=l+(r-l)/2;
			if(m[sum][mid]>=i){
				r=mid-1;
				ans=mid;
			}
			else l=mid+1;
		}
		if(ans<0) continue;
		ran[++cnt]=(range){i,m[sum][ans]};
	}
	sort(ran+1,ran+cnt+1);
	int now=0,tot=0;
	for(int i=1;i<=cnt;i++){
		if(now>=ran[i].l) continue;
		tot++;
		now=ran[i].r;
	}
	cout<<tot;
	return 0;
}
