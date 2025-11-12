#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000005],b[1000005],w[1000005],fg[1000005],c[15];
long long s[15][10005],fa[20001],g[15][10005],anss;
priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q; 
int find(int x){
	if(fa[x]==x){
		return x;
	}
	else {
		return fa[x]=find(fa[x]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,ww;
		scanf("%lld%lld%lld",&u,&v,&ww);
		//cin>>u>>v>>ww;
		if(u>v)
		swap(u,v);
		a[i]=u;b[i]=v;
		w[i]=ww;
		q.push({ww,i});
	}
	priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>p; 
	for(int i=1;i<=n;i++)fa[i]=i;
	for(;!q.empty();){
		pair<long long,long long>o=q.top();
		q.pop();
		int x=o.second; 
		if(find(a[x])!=find(b[x])){
			anss+=w[x];
			//cout<<anss<<endl;
			p.push(o);
			fa[find(a[x])]=find(b[x]);
		}
	}
	//cout<<anss<<endl;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		//priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pp=p; 
		for(int j=1;j<=n;j++){
			scanf("%lld",&s[i][j]);
			//pp.push({s[i][j],j});
		}
	}
	for(int i=0;i<(1<<(k));i++){
		long long ans=0,sz=n;
		priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pp=p; 
		for(int j=1;j<=k;j++){
			if(((i>>(j-1))&1)){
				ans+=c[j];
				sz++;
				for(int l=1;l<=n;l++)
				pp.push({s[j][l],m+j*n+l});
			}
		}
		//cout<<ans<<" test"<<endl;
		for(int j=1;j<=n+k;j++)fa[j]=j;
		for(;!pp.empty();){
			if(sz==1){
				break;
			}
			//cout<<ans<<endl;
			pair<long long,long long>o=pp.top();
			pp.pop();
			int x=o.second; 
			//cout<<"test "<<o.first<<" "<<o.second<<endl;
			if(x>m){
				int xx,yy;
				//cout<<"test "<<xx<<" "<<yy<<endl;
				x-=m;
				if(x%n==0) xx=x/n-1,yy=n;
				else xx=x/n,yy=x%n;
				
				if(find(yy)!=find(xx+n)){//cout<<"test "<<xx<<" "<<yy<<" "<<o.first<<endl;
					ans+=s[xx][yy];sz--;
					fa[find(yy)]=find(xx+n);
				}
			}
			else{
				if(find(a[x])!=find(b[x])){//cout<<"test "<<o.first<<" "<<o.second<<endl;
					ans+=w[x];sz--;
					fa[find(a[x])]=find(b[x]);
				}				
			}

		}
		//cout<<"test "<<ans<<endl;
		anss=min(ans,anss);
	}
	cout<<anss<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/

