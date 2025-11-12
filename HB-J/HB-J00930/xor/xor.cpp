#include <bits/stdc++.h>
using namespace std;
long long n,k,m[500005],ans;
struct node{
	long long st,en;
}s[500005];
bool cmp(node x,node y){
	if(x.en!=y.en)return x.en<y.en;
	return x.st>y.st;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(long long i=1;i<=n;i++){
		cin>>m[i];
	}
	long long sum=0;
	long long ii=1;
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			sum=m[j]^sum;
			if(sum==k){
				s[ii].st=i;
				s[ii].en=j;
				ii++;
				sum=0;
				break;
				
			}
		}
		sum=0;
	}
	sort(s+1,s+1+n,cmp);
	long long l=0;
	for(long long i=1;i<=n;i++){

		if(s[i].st>l) {
			ans++;
			l=s[i].en;
		}
	}
	cout<<ans;
	return 0;
}
