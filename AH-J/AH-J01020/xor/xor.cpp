#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,k;
long long a[N];
long long ans=0;
long long lastl=-1,lastr=-1;
bool vis[N];

long long work(long long i){
	if (a[i]==k) return 1;
	long long sum=a[i],cnt=1;
	i++;
	while (sum!=k && i<=n){
		sum^=a[i];
		i++;
		cnt++;
	}
	if (sum==k) return cnt;
	else return -1;
}

bool check(long long l,long long r){
	for (long long i=l;i<=r;i++){
		if (a[i]==k) return 0;
	}
	if ((l>=lastl && l<=lastr) || (r>=lastl && r<=lastr)) return 0;
	else return 1;
}//shi shi fou wei tong yi ge qu jian 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	long long i;
	for (i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt,l,r;
	for (i=1;i<=n;i++){
		if (a[i]==k){
			ans++;
			lastl=i;
			lastr=i;
			continue;
		}
		cnt=work(i);
		if (cnt==-1) continue;
		l=i;
		r=l+cnt-1;
		if (check(l,r)){
			lastl=l;
			lastr=r;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
