#include<bits/stdc++.h>
using namespace std;
void op(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
}
long long sum[1000006],n,k,a[1000006],dp[1000006],ans,last=0;
struct tt{
	long long l,r;
};
long long work(long long ll,long long rr){
	return sum[rr]^sum[ll-1];
}
bool cmp(tt x,tt y){
	if(x.r==y.r){
		return x.l>y.l;
	}
	return(x.r<y.r);
}
vector<tt> v;
int main(){
	op();
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			long long s=work(i,j);
			if(s==k){
				v.push_back({i,j});
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	long long last=0;
	for(long long i=0;i<v.size();i++){
		if(v[i].l>v[last].r||i==0){
			ans++;
			last=i;
		}
	}
	cout<<ans;
	return 0;
}
