#include<bits/stdc++.h>
#define lowbit(x) x&-x
using namespace std;
const long long mod=998244353;
int n;
long long l=0,ans=0;
long long tree[50005];
long long a[50005];
long long jl[50005];
void add(int pos,long long val){
	while(pos<=l){
		tree[pos]+=val;
		tree[pos]%=mod;
		pos+=lowbit(pos);
	}
}long long ask(int pos){
	long long sum=0;
	while(pos>0){
		sum+=tree[pos];
		sum%=mod;
		pos-=lowbit(pos);
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		l+=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans+=(max(ask(l)-ask(a[i]),0ll)+mod)%mod;//·ÀÖ¹¸ºÊý 
		for(int j=l-a[i];j>=1;j--){
			jl[j]%=mod;
			if(jl[j]!=0){
				jl[j+a[i]]+=jl[j];
				add(j+a[i],jl[j]);
			}
		}
		for(int j=1;j<i;j++){
			jl[a[i]+a[j]]++;
			jl[a[i]+a[j]]%=mod;
			add(a[i]+a[j],1);
		}
	}
	cout<<(ans+mod)%mod;
	return 0;
}

