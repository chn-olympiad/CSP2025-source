#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[510000];
int c[510000];
struct node{
	int l,r,ans;
};
vector<node> o;
int ans;
void dfs(vector<node> d,int x,int s){
	for(int i=1;i<=s;i++){
		if(o[x].l==d[i].l||o[x].l==d[i].r||o[x].r==d[i].l||o[x].r==d[i].r
		||(o[x].l>d[i].l&&o[x].l<d[i].r)||(o[x].r>d[i].l&&o[x].r<d[i].r)||
		(d[i].l>o[x].l&&d[i].l<o[x].r)||(d[i].r>o[x].l&&d[i].r<o[x].r)){
//			cout<<i<<endl;
			return ;
		}
	}
	s++;
	ans=max(s,ans);
	d.push_back(o[x]);
	for(int i=x+1;i<o.size();i++){
		dfs(d,i,s);
	}
//	cout<<o[x].ans<<" ";
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=c[i-1] xor a[i];
	}
//	for(int i=1;i<=n;i++){
//		cout<<c[i]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int liu=c[j] xor c[i-1];
			if(liu==k){
//				cout<<liu<<endl;
				o.push_back({i,j});	
			}
		}
	}
//	for(int i=0;i<o.size();i++){
//		cout<<o[i].l<<" "<<o[i].r<<endl;
//	}
	for(int i=0;i<o.size();i++){
		vector<node> eee;
		eee.push_back(o[i]);
		dfs(eee,i,0);
	}
	cout<<ans;
	return 0;
}
/*
4 3
2 1 0 3
*/
