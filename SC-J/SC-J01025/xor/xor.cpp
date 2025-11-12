#include<bits/stdc++.h>
using namespace std;
int n,k,sta,cnt,cnt1;
const int N=5e5+5;
int a[N];
pair<int,int> b[N];
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.second!=b.second) return a.second<b.second;
	return a.first<b.first;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		long long sum,x;
		if(k==0) sum=a[i],x=i+1;
		else sum=0,x=i;
		while(sum!=k&&x<=n){
			sum^=a[x];
			x++;
		}
		if(sum==k){
			cnt1++;
			b[cnt1].first=i,b[cnt1].second=x-1;
		}
	}
	sort(b+1,b+1+cnt1,cmp);
	for(int i=1;i<=cnt1;i++){
		if(b[i].first>sta){
			cnt++;
			sta=b[i].second;
		}
	}
	cout<<cnt;
	return 0;
}