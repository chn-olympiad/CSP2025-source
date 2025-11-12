#include <bits/stdc++.h>
using namespace std;
#define int long long 
//异或怎么打？？？
//^?
//应该是用双指针
//好像没有单调性？？？
int a[500100];
struct node {
	int l,r;
};
vector<node>v;
int sum[500100];
bool cmp(node a,node b){
	if(a.r!=b.r)return a.r<b.r;
	else return a.l>b.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//cout<<"end";
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++){
			int t=sum[i]^sum[j];
			if(t==k){
				v.push_back({j+1,i});
			}
		}
	}
	if(v.empty()){
		cout<<0;
		return 0;
	}
	sort(v.begin(),v.end(),cmp);
	int l=v[0].r;
	int ans=1;
	for(size_t i=1;i<v.size();i++){
		if(v[i].l>l){
			l=v[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
