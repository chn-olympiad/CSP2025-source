#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010];
struct node{
	long long l,r;
};
vector<node>v;
long long f(long l,long r){
	if(l==r) return a[l];
	long long sum=0;
	for(long long i=l;i<=r;i++){
		sum^=a[i];
	}
	return sum;
}
bool cmp(node x,node y){
	if(x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			long long p=f(i,j);
			if(p==k){
				node z={i,j};
				v.push_back(z);
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	
	long long maxn=0,sk=v.size();
	for(long long i=0;i<sk;i++){
		long long ans=0;
		for(long long j=0;j<sk-i-1;j++){
			long long tmp=v[i].r;
			if(tmp<v[i+j].l){
				ans++;
				tmp=v[i+j].r;
			}
		}
		maxn=max(ans,maxn);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
