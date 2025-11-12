#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll a[N],sum[N];
struct sted{
	ll st,ed;
}tim[N];
bool cmp(sted x,sted y){
	if(x.st==y.st)return x.ed<y.ed;
	return x.st<y.st;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,idx=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	ll cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[i-1])==k)tim[idx++]=(sted){i,j};
		}
	}
	ll last;
	sort(tim+1,tim+idx,cmp);
	for(int i=1;i<idx;i++){
		if(i==1){
			last=tim[i].ed;
			cnt++;
			continue;
		}
		if(tim[i].st>=last+1){
			last=tim[i].ed;
			cnt++;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
