#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500010];
long long ans=0;
void dfs(long long x,long long cnt){
	if(x>=n)return;
	int l,r;
	bool flag=0;
	for(l=x;l<n;l++){
		int s=0;
		for(r=l;r<n;r++){
			s^=a[r];
			if(s==k){
				flag=1;
				break;
			}
		}
		if(flag)break;
	}
	if(flag==0){
		return;
	}
	ans=max(ans,cnt+1);
	dfs(r+1,cnt+1);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
};
bool cmp(node a,node b){
	if(a.r==b.r)return a.l<b.l;
	return a.r<b.r;
}
vector<node>vec;

long long n,k;
long long a[500010];
long long ans=0;
void dfs(long long x,long long cnt,long long last){
	if(cnt>ans){
		ans=cnt;
	}
	if(x>=((long long)vec.size()))return;
	
	dfs(x+1,cnt,last);
	if(last!=-1){
		if(vec[last].r<vec[x].l){
			dfs(x+1,cnt+1,x);
		}
	}else{
		dfs(x+1,cnt+1,x);
	}
	return;
}
int main(){
	freopen("xor3.in","r",stdin);
	freopen("xor3.out","w",stdout);
	cin>>n>>k;
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	int l,r;
	for(l=0;l<n;l++){
		int s=0;
		for(r=l;r<n;r++){
			s^=a[r];
			if(s==k){
				vec.push_back({l,r});
				break;
			}
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	dfs(0,0,-1);
	cout<<ans;
	return 0;
}

 */
