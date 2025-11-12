#include<bits/stdc++.h>
using namespace std;

const int N=1e5,V=2e4;

int t;
int n;
int a[3][N+5],mx[N+5];
int c[N+5];
int cnt[N+5];

int tt[V+5];

int exc(int x){
	if(c[x]==0){
		return min(a[0][x]-a[1][x],a[0][x]-a[2][x]);
	}
	if(c[x]==1){
		return min(a[1][x]-a[0][x],a[1][x]-a[2][x]);
	}
	if(c[x]==2){
		return min(a[2][x]-a[0][x],a[2][x]-a[1][x]);
	}
	return 0;
}

int adj(int id){
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=a[c[i]][i];
	}
	for(int i=1;i<=n;++i){
		if(c[i]==id){
			++tt[exc(i)];
		}
	}
	int num=cnt[id]-n/2;
	for(int i=0;i<=V;++i){
		while(num!=0 && tt[i]!=0){
			ans-=i;
			--num;
			--tt[i];
		}
	}
	for(int i=0;i<=V;++i){
		tt[i]=0;
	}
	return ans;
}

int get_ans(){
	for(int i=0;i<3;++i){
		if(cnt[i]>n/2){
			return adj(i);
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans+=a[c[i]][i];
	}
	return ans;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cnt[0]=0;
		cnt[1]=0;
		cnt[2]=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[0][i]>>a[1][i]>>a[2][i];
			mx[i]=max(a[0][i],max(a[1][i],a[2][i]));
		}
		for(int i=1;i<=n;++i){
			for(int j=0;j<3;++j){
				if(a[j][i]==mx[i]){
					c[i]=j;
					break;
				}
			}
			++cnt[c[i]];
		}
		cout<<get_ans()<<'\n';
	}
	return 0;
}
