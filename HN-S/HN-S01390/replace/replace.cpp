#include<bits/stdc++.h>
using namespace std;
int n,m,k,l,r,u,u2,num,sum,ans,a[5000010][30],b[5000010][30],c[5000010],d[5000010],e[5000010],f[5000010],g[200010];
vector<long long> v[5000010],w[5000010];
string q,p;
queue<int> o;
int main(  ){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q>>p;
		l=0,r=q.size( );
		for(int j=0;j<r;j++){
			if(a[l][q[j]-'a'+1]==0){
				num++;
				a[l][q[j]-'a'+1]=num;
				e[num]=j+1;
			}
			l=a[l][q[j]-'a'+1];
		} 
		v[l].push_back(i);
		l=0,r=p.size( );
		for(int j=0;j<r;j++){
			if(b[l][p[j]-'a'+1]==0){
				sum++;
				b[l][p[j]-'a'+1]=sum;
				f[sum]=j+1;
			}
			l=b[l][p[j]-'a'+1];
		} 
		w[l].push_back(i);
	}
	for(int i=1;i<=26;i++){
		if(a[0][i]) o.push(a[0][i]);
	}
	while(o.empty( )==0){
		l=o.front( ),o.pop( );
		for(int i=1;i<=26;i++){
			if(a[l][i]==0) a[l][i]=a[c[l]][i];
			else{
				c[a[l][i]]=a[c[l]][i];
				o.push(a[l][i]);
			}
		}
	}
	for(int i=1;i<=26;i++){
		if(b[0][i]) o.push(b[0][i]);
	}
	while(o.empty( )==0){
		l=o.front( ),o.pop( );
		for(int i=1;i<=26;i++){
			if(b[l][i]==0) b[l][i]=b[d[l]][i];
			else{
				d[b[l][i]]=b[d[l]][i];
				o.push(b[l][i]);
			}
		}
	}
	for(int i=1;i<=m;i++){
		cin>>q>>p;
		k=q.size( );
		l=0,r=k-1,ans=0;
		while(l<k&&q[l]==p[l]) l++;
		while(r&&q[r]==p[r]) r--;
		u=0;
		for(int j=0;j<k;j++){
			u=a[u][q[j]-'a'+1];
			if(j>=r){
				u2=u;
				while(u2){
					if(e[u2]<j-l+1) break;
					for(int i2=0;i2<v[u2].size( );i2++){
						g[v[u2][i2]]=1;
					}
					u2=c[u2];
				}
			}
		}
		u=0;
		for(int j=0;j<k;j++){
			u=b[u][p[j]-'a'+1];
			if(j>=r){
				u2=u;
				while(u2){
					if(f[u2]<j-l+1) break;
					for(int i2=0;i2<w[u2].size( );i2++){
						if(g[w[u2][i2]]==1){
							g[w[u2][i2]]=2;
							ans++;
						}
					}
					u2=d[u2];
				}
			}
		}
		u=0;
		for(int j=0;j<k;j++){
			u=a[u][q[j]-'a'+1];
			if(j>=r){
				u2=u;
				while(u2){ 
					if(e[u2]<j-l+1) break;
					for(int i2=0;i2<v[u2].size( );i2++){
						g[v[u2][i2]]=0;
					}
					u2=c[u2];
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
