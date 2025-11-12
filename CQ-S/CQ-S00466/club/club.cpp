#include <bits/stdc++.h>

using namespace std;

int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){f=(c=='-'?-1:1);c=getchar();
	}while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();
	}return x*f;
}
typedef pair<int,pair<int,int> > pii;
const int N=1e5+10;
int n;
int a[N][4];
int cnt[4];
pair<int,int> b[N][4];
bool cmp1(pair<int,int> a,pair<int,int> b){
	return a.first>b.first;
}
struct node{
	int maxn[4],g[4];
	int mx;
}h[N];
bool cmp(node i,node j){
	return i.mx>j.mx;
}
priority_queue<pii,vector<pii>,greater<pii> > q[4];
int mx=0;
	void dfs(int x,int sum){ 
		if(x==n+1){
			if(sum>mx){
				mx=sum;
			}
			return ;
		}
		if(cnt[1]<n/2){
			cnt[1]++;
			dfs(x+1,sum+a[x][1]);
			cnt[1]--;
		}
		if(cnt[2]<n/2){
			cnt[2]++;
			dfs(x+1,sum+a[x][2]);
			cnt[2]--;
		}
		if(cnt[3]<n/2){
			cnt[3]++;
			dfs(x+1,sum+a[x][3]);
			cnt[3]--;
		}
	}
void solve(){
	memset(cnt,0,sizeof cnt);
	if(n<=10){
		n=read();
		int h=n/2;
		mx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
			}
		}
		dfs(1,0);
		cout<<mx<<endl;
		return; 
	}
	n=read();
	bool f=0;
	for(int i=1;i<=n;i++){
		a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		b[i][1]={a[i][1],1},b[i][2]={a[i][2],2},b[i][3]={a[i][3],3};
		if(a[i][1]!=0 || a[i][3]!=0) f=1;
		sort(b[i]+1,b[i]+1+3,cmp1);
		h[i].mx=b[i][1].first;
		for(int j=1;j<=3;j++){
			h[i].maxn[j]=b[i][j].first;
			h[i].g[j]=b[i][j].second;
		}
	}
	if(f==0){
		n=read();
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			b[i][1]={a[i][1],1},b[i][2]={a[i][2],2},b[i][3]={a[i][3],3};
			sort(b[i]+1,b[i]+1+3,cmp1);
			h[i].mx=b[i][1].first;
			for(int j=1;j<=3;j++){
				h[i].maxn[j]=b[i][j].first;
				h[i].g[j]=b[i][j].second;
			}
		}
		sort(h+1,h+1+n,cmp);
		int ret=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				//cout<<cnt[h[i].g[j]]<<" "<<h[i].maxn[j]<<endl;;
				if(cnt[h[i].g[j]]<n/2){
					ret+=h[i].maxn[j];	
					cnt[h[i].g[j]]++;
					break;
				}
			}
		} 
		cout<<ret<<endl;
		return ;
	}
	sort(h+1,h+1+n,cmp);
	int ret=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(q[h[i].g[j]].size()<n/2){
				ret+=h[i].maxn[j];
				//cout<<i<<" "<<h[i].g[j]<<" "<<h[i].maxn[j]<<endl;
				q[h[i].g[j]].push({h[i].maxn[j],{j,i}});
				break;
			}
			else if(q[h[i].g[j]].size()==n/2){
				auto t=q[h[i].g[j]].top();
				if(h[i].maxn[j]>t.first){
					q[h[i].g[j]].pop();
					ret-=t.first;
					int rk=t.second.first,hang=t.second.second;
					//cout<<t.first<<" "<<rk<<" "<<hang<<" "<<h[hang].maxn[rk]<<endl;
					for(int k=rk+1;k<=3;k++){
						if(q[h[hang].g[k]].size()<n/2){
							q[h[hang].g[k]].push({h[hang].maxn[k],{k,hang}});
							ret+=h[hang].maxn[k];
						}
					}
					q[h[i].g[j]].push({h[i].maxn[j],{j,i}});
					ret+=h[i].maxn[j];
				}
			}
		}	
	}
	cout<<ret<<endl;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	//freopen("club.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/

