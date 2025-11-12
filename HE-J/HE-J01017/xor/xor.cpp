#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+1;
int n,k,a[maxn];
struct node{
	int l,r;
};
vector<node> v;
int sum(int l,int r){
	int ans=a[l];
	for(int i=l+1;i<=r;i++){
		ans=ans^a[i];
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(sum(i,j)==k){
				v.push_back(node{i,j});
			}
		}
	}
	int ans=0,len=v.size(),l=0;
	for(int i=0;i<len;i++){
		if(l<v[i].l){
			ans++;
			l=v[i].r;
//			cout<<l<<" "<<v[i].l<<" "<<v[i].r<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
4 2  
2 1 0 3
4 3 
2 1 0 3
4 0 
2 1 0 3
*/
