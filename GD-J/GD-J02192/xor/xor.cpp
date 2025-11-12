#include <iostream>
#include <queue>
using namespace std;
constexpr int N=500005;

struct node{
	int l,r;
};

int n,k,a[N],sum[N],lnum[N],ans,rnum[N];
queue<node> q;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==k) q.push(node{i,i}),++lnum[i],++rnum[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(sum[j]^sum[i-1]==k){
				q.push(node{i,j});
				++lnum[i];
				++rnum[j];
			}
		}
	}
	cout<<(sum[3]^sum[1])<<endl;
	while(q.size()){
		node u=q.front();
		q.pop();
		ans=max(ans,rnum[u.l-1]+lnum[n]-lnum[u.r]+1);
	}
	cout<<ans;
	return 0;
}
