#include<bits/stdc++.h>
#define pll pair<long long,long long>
using namespace std;
long long n,k,b[500005],s=-1,ans;
vector<pll >v;
struct r{long long x,i;
}a[500005];
bool cmp1(r a,r b){
	if(a.x!=b.x)return a.x<b.x;
	return a.i<b.i;
}
bool cmp2(pll a,pll b){return a.second<b.second;}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i].x,a[i].i=i,a[i].x^=a[i-1].x;
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++)b[i]=a[i].x;
	for(int i=0;i<=n;i++){
		int tmp=b[i]^k;
		int l=lower_bound(b+1,b+n+1,tmp)-b,r=upper_bound(b+1,b+n+1,tmp)-b;
		for(int j=l;j<r;j++)if(a[i].i+1<=a[j].i){
			v.push_back(make_pair(a[i].i+1,a[j].i));
			break;
		}
	}
	sort(v.begin(),v.end(),cmp2);
	for(pll i:v)if(i.first>s)ans++,s=i.second;
	cout<<ans;
	return 0;
}
