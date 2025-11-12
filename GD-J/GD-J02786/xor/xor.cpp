#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
long long n,k,a[maxn],ans=0,sum=0;
struct pr{
	long long a,b;
}p[100*maxn];
bool cmp(pr a,pr b){
	if(a.b!=b.b){
		return a.b<b.b;
	}else{
		return a.a>b.a;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int rc=0;
		for(int j=i;j<=n;j++){
			rc^=a[j];
			if(rc==k){
				p[++sum].a=i;
				p[sum].b=j;
				break;
			}
		}
	}
	sort(p,p+sum+1,cmp);
	long long rc=0;
	for(long long i=1;i<=sum;i++){
		if(p[i].a>rc){
			rc=p[i].b;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
