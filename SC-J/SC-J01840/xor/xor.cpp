#include<bits/stdc++.h>
using namespace std;
using LL=long long;
LL f(LL x,LL y){
	LL cnt=0,i=1;
	while(x>0&&y>0){
		if(x%2!=y%2)cnt+=i;
		x/=2,y/=2;
		i*=2;
	}
	while(x>0)cnt+=i*(x%2),i*=2,x/=2;
	while(y>0)cnt+=i*(y%2),i*=2,y/=2;
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	//cout<<f(n,k);
	LL a[n+1]={},sum[n+1]={};
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)sum[i]=f(a[i],sum[i-1]);
	vector<pair<LL,LL>> cnt;
	int N=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(f(sum[i-1],sum[j])==k){
				pair<int,int> x;
				x.first=i,x.second=j;
				cnt.push_back(x);
				N++;
			}
	int ans=0;
	for(int i=0;i<N;i++){
		LL r=cnt[i].second,num=1;
		for(int j=i;j<N;j++)
			if(cnt[j].first>r)
					r=cnt[j].second,num++;
		ans=max(ans,num);
	}
//	cout<<N<<' ';
	cout<<ans;
	return 0;
}