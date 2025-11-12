#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum[500005],cnt;
map<int,int>lst;
struct node{int l,r;}m[500005];
bool cmp(node a,node b){
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sum[0]=0;lst[0]=0;
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]^a[i];
		int op=sum[i]^k;
//		cout<<sum[i]<<" "<<op<<'\n';
//		cout<<lst[op]<<'\n';
		if(!lst.count(sum[i]^k)){
			lst[sum[i]]=i;
			continue;
		}
		++cnt;
		m[cnt].l=lst[sum[i]^k]+1;
		m[cnt].r=i;
		lst[sum[i]]=i;
	} 
//	cout<<sum[3]<<" "<<sum[4]<<endl;
//	cout<<cnt<<'\n';
	sort(m+1,m+cnt+1,cmp);
	int lstr=-1,ans=0;
	for(int i=1;i<=cnt;++i){
		if(m[i].l>lstr){
			ans++;
			lstr=m[i].r;
		}
//		cout<<m[i].l<<" "<<m[i].r<<'\n';
	}
	cout<<ans;
	return 0;
}
