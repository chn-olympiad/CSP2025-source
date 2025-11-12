#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;

struct node{
	int l,r;
};
vector<node> v;

int n,k,a[N],pre[N],ans;

bool cmp(node x,node y){
	return x.r<y.r;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(pre[j]^pre[i-1]==k){
				v.push_back({i,j});
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	int len=v.size(),now=0;
	for(int i=1;i<=n;i++){
		if(now<v[i].l){
			now=v[i].r;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
