#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k;
int a[maxn];
int s[maxn];
int xxor(int l,int r){
	return (s[r]^s[l-1]);
}
pair<int,int> p[maxn];
int q=0;
bool cmp(pair<int,int> x,pair<int,int> y){
	return x.second<y.second;
}
int ans=0;
int res=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++){
		if(xxor(i,j)==k) p[++q]=make_pair(i,j);
	}
	sort(p+1,p+q+1,cmp);
	for(int i=1;i<=q;i++){
		
		if(p[i].first>p[res].second) res=i,ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
