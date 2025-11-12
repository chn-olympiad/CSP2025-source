#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,k,a[N],pref[N],ans;
int xos(int l,int r){return pref[r]^pref[l-1];}
int test1(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<xos(i,j)<<endl;
			if(xos(i,j)==k){
//				cout<<i<<" "<<j<<endl;
				i=j;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
}
vector<pair<int,int> >v;
int find(int x){
	int l=1,r=m,res=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(v[mid].first>=x){
			res=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return res;
}
int vis[N];
void dfs(int pos,int res){
	if(pos>n){
		ans=max(ans,res);
		return ;
	}
	if(vis[pos]>res) return ;
	vis[pos]=res;
	int tot=find(pos);
	if(tot==-1){
		dfs(n+1,res);
		return ;
	}
	for(int i=tot;i<=m;i++){
		dfs(v[i].second+1,res+1);
	}
}
int test2(){
	v.push_back({0,0});
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(xos(i,j)==k){
				v.push_back(make_pair(i,j));
				m++;
			}
	vis[1]=-1;
	dfs(1,0);
	cout<<ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) pref[i]=pref[i-1]^a[i];
	if(n<=10){
		test2();
	}else{
		test1();
	}
	return 0;
}
