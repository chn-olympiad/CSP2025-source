#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,q,nxt[2][N],ans[N],b[N];
string t[N][2],s[N][2];
void getnxt(string x,int f){
	int j=0,k=-1;
	for(int j=0;j<x.size();++j)nxt[f][j]=0;
	nxt[f][0]=-1;
	while(j<x.size()){
		if(k==-1||x[k]==x[j])nxt[f][++j]=++k;
		else k=nxt[f][k];
	}
}
int solve(string x,string y,string p,string g){
	queue<int>q;
	for(int i=-1,j=-1;i<(int)x.size();){
		if(j==-1||x[i]==y[j]){
			++i;++j;
		} else j=nxt[0][j];
		if(j==y.size()){
			q.push(i-1);
			b[i-1]=1;
			j=nxt[0][j];
//			cout<<x<<" "<<y<<" "<<p<<" "<<g<<" "<<1<<" "<<i<<"\n";
		}
	}
	for(int i=-1,j=-1;i<(int)p.size();){
		if(j==-1||g[j]==p[i]){
			++i;++j;
		} else j=nxt[1][j];
		if(j==g.size()){
			if(b[i-1]==1){
				while(!q.empty()){
					b[q.front()]=0;
//					cout<<q.front()<<"\n\n";
					q.pop();
				}
//				cout<<x<<" "<<y<<" "<<p<<" "<<g<<" "<<i<<"\n";
				return i-j;
			}
			j=nxt[1][j];
		}
	}
	while(!q.empty()){
		b[q.front()]=0;
//		cout<<q.front()<<"\n\n";
		q.pop();
	}
	return -1;
}
bool pd(string x,string y,int l,int r){
	for(int i=0;i<l;++i){
		if(x[i]!=y[i]){
			return 0;
		}
	}
	for(int i=r;i<x.size();++i){
		if(x[i]!=y[i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i)cin>>t[i][0]>>t[i][1];
	for(int i=1;i<=q;++i)cin>>s[i][0]>>s[i][1];
	for(int i=1;i<=n;++i){
		getnxt(t[i][0],0);
		getnxt(t[i][1],1);
		for(int j=1;j<=q;++j){
			if(s[j][0].size()!=s[j][1].size())continue;
			int pp=solve(s[j][0],t[i][0],s[j][1],t[i][1]);
			if(pp==-1)continue;
			if(pd(s[j][0],s[j][1],pp,pp+t[i][0].size()))++ans[j];
		}
	}
	for(int i=1;i<=q;++i)cout<<ans[i]<<"\n";
	return 0;
}

