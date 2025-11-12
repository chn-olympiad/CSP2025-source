#include<bits/stdc++.h>
using namespace std;
struct sd{
	int l,r;
};
int a[514514];
int t[2919810];
int n,k;
vector<sd> v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(t,-1,sizeof t);
	t[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
		if(t[k^a[i]]!=-1){
			v.push_back({t[k^a[i]]+1,i});
		}t[a[i]]=i;
	}int cnti=1,R=v[0].r;
	for(int i=1;i<v.size();i++){
		if(v[i].l>R){
			cnti++;
			R=v[i].r;
		}
	}cout<<cnti;
	return 0;
} 
