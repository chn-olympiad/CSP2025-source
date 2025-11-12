#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,b[N],ans,k,tot;
map<int,vector<int> >mp;
map<int,int> front;
struct node{
	int l,r,len;
}c[N];
bool ok(int l,int r,int L,int R){
	if(l<L&&r<L)return 1;
	if(l>R&&r>R)return 1;
	return 0;
}
bool cmp(node x,node y){
	if(x.r==y.r){
		return x.len<y.len;
	} 
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=(b[i-1]^a[i]); 
		mp[b[i]].push_back(i);
//		cout<<b[i]<<" ";
	}
//	cout<<endl; 
	for(int i=1;i<=n;i++){
		int g=(b[i-1]^k);
		int v=mp[g].size(),j=front[g];
		while(j<v&&mp[g][j]<i){
			j++;
		}
		front[g]=j;
		if(j==v){
			continue;
		} 
		c[++tot]={i,mp[g][j],mp[g][j]-i+1};
//		cout<<"C::"<<i<<" "<<mp[g][j]<<endl;
	}
	if(tot==0){
		cout<<"0";
		return 0;
	} 
	sort(c+1,c+tot+1,cmp);
	ans=1;
	int p=1;
	for(int i=2;i<=tot;i++){
		if(ok(c[p].l,c[p].r,c[i].l,c[i].r)){
			ans++;
			p=i;
		}
	}
	cout<<ans;
	return 0;
} 
/*
5 7
2 1 4 5 2 
*/
