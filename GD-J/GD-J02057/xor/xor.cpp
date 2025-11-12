#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
};
int n,k,a[500001],s[500001],cnt,endss=-1;
vector<node>v;
int xorr(int l,int r){
	return s[l-1]^s[r];
}
bool cmp(node a,node b){
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
//	for(int i=0;i<=n;i++) cout<<i<<":"<<s[i]<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(xorr(i,j)==k){
				v.push_back({i,j});
//				cout<<xorr(i,j)<<" "<<i<<" "<<j<<endl;
			}
		}
	}
//	for(int i=0;i<v.size();i++) cout<<v[i].l<<" "<<v[i].r<<endl;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		if(v[i].l>endss){
			endss=v[i].r;
			cnt++;
		}
	}
	cout<<cnt;
}
