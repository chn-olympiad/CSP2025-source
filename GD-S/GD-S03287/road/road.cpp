#include<bits/stdc++.h>
using namespace std;
struct bi{
	int a,b,l;
}v[10000007];

struct xi{
	int f;
	int li[10007];
}x[17];

bool cmd(bi a,bi b){
	return a.l<b.l;
}

int bc[10007];

int fi(int n){
	if(bc[n]==n){
		return n;
	}
	return bc[n]=fi(bc[n]);
}

bool vis[10007];

long long n,m,k,h=0;

void ah(){
	for(int i=1;i<=m;i++){
		cin>>v[i].a>>v[i].b>>v[i].l;
	}
	for(int i=1;i<=k;i++){
		cin>>x[i].f;
		for(int j=1;j<=n;j++){
			cin>>x[i].li[j];
		}
		for(int j=1;j<=n;j++){
			for(int o=1;o<=n;o++){
				if(j==o){
					continue;
				}
				v[++m].a=j;
				v[m].b=o;
				v[m].l=x[i].li[j]+x[i].li[o];
			}
		}
	}
	sort(v+1,v+m+1,cmd);
	for(int i=1;i<=n;i++){
		bc[i]=i;
	}
	int g=0;
	for(int i=1;i<=m;i++){
		if(fi(v[i].a)!=fi(v[i].b)){
			h+=v[i].l;
			bc[fi(v[i].a)]=fi(v[i].b);
			g++;
		}
		if(g==n-1){
			break;
		}
	}
	cout<<h;
}

void bh(){
	for(int i=1;i<=m;i++){
		cin>>v[i].a>>v[i].b>>v[i].l;
	}
	for(int i=1;i<=k;i++){
		cin>>x[i].f;
		for(int j=1;j<=n;j++){
			cin>>x[i].li[j];
		}
	}
	sort(v+1,v+m+1,cmd);
	for(int i=1;i<=n;i++){
		bc[i]=i;
	}
	int g=0;
	for(int i=1;i<=m;i++){
		if(fi(v[i].a)!=fi(v[i].b)){
			h+=v[i].l;
			bc[fi(v[i].a)]=fi(v[i].b);
			g++;
		}
		if(g==n-1){
			break;
		}
	}
	cout<<h;
}

int main(){
		freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	if(k>0){
		ah();
	}
	else{
		bh();
	}
	return 0;
}
