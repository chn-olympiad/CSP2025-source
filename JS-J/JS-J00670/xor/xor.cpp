#include<bits/stdc++.h>
using namespace std;
struct NODE{
	int l,r;
};
bool cmp(NODE a,NODE b){
	return (a.l<b.l);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<NODE> a,b;
	vector<int> sum(n+1,0);
	map<int,int> s;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		sum[i]=sum[i-1]^x;
		if(x==k){
			a.push_back({i,i});
			s[sum[i]]=i;
			continue;
		}
		int y=x^k;int c=sum[i-1]^y;
		if(s[c]||!c) a.push_back({s[c]+1,i});
		s[sum[i]]=i;
	}
	int nn=a.size(),cnt=0,ans=0,r=0;
	sort(a.begin(),a.end(),cmp);
	if(nn) b.push_back(a[0]);
	for(int i=1;i<nn;i++){
		if(a[i].l==b[cnt].l) b[cnt]=(a[i].r>=b[cnt].r)?b[cnt]:a[i];
		else if(a[i].r<=b[cnt].r) b[cnt]=a[i];
		else{
			b.push_back(a[i]);
			cnt++;
		}
	}
	//for(auto x:b) cout<<x.l<<" "<<x.r<<'\n';
	if(b.size()){
		ans=1;
		r=b[0].r;
	}
	for(int i=1;i<=cnt;i++){
		if(b[i].l>r){
			ans++;r=b[i].r;
		}
	}
	cout<<ans;
	return 0;
}
