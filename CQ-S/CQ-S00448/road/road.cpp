#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int a,b,c;
	node(){
		
	}
	node(int x,int y,int z){
		a=x;
		b=y;
		c=z;
	}
}e[1000010],ed[1000010],Exa[1000010],tmp[1000010];
int cex;
int cnt;
int n,m,k;
int c[20];
int a[15][10010];
int f[10050];
int getf(int x){
	return (f[x]==x)?(x):(f[x]=getf(f[x]));
}
bool cmp(node a,node b){
	return a.c<b.c;
}
ll calc(int s){
	int cee=0;
	//cout<<"s:"<<s<<endl;
	node*e1=ed;
	int cnt=n-1;
	//cout<<"cnt:"<<cnt<<endl;
	cex=0;
	for(int i=1;i<=n*k;i++){
		int id=tmp[i].a-n-1;
		if((s>>id)&1){
			Exa[++cex]=tmp[i];
			//cout<<id<<endl;
		}
	}
	//cout<<"cex:"<<cex<<endl;
	for(int i=1;i<=n+k;i++)f[i]=i;
	ll res=0;
	int p1=1,p2=1;
	while(p1<=cnt&&p2<=cex){
		node tmp;
		if(e1[p1].c<Exa[p2].c){
			tmp=e1[p1];
			p1++;
		}
		else{
			tmp=Exa[p2];
			p2++;
		}
		int a=getf(tmp.a),b=getf(tmp.b);
		if(a!=b){
			f[a]=b;
			res+=tmp.c;
			cee++;
			//cout<<tmp.c<<endl;
		}
	}
	while(p1<=cnt){
		node tmp=e1[p1];
		p1++;
		int a=getf(tmp.a),b=getf(tmp.b);
		if(a!=b){
			f[a]=b;
			res+=tmp.c;
			cee++;
			//cout<<tmp.c<<endl;
		}
	}
	while(p2<=cex){
		node tmp=Exa[p2];
		p2++;
		int a=getf(tmp.a),b=getf(tmp.b);
		if(a!=b){
			f[a]=b;
			res+=tmp.c;
			cee++;
			//cout<<tmp.c<<endl; 
		}
	}
	//cout<<"cee:"<<cee<<endl;
	//cout<<"res:"<<res<<endl;
	for(int i=0;i<k;i++){
		if((s>>i)&1){
			res+=c[i];
		}
	}
	//cout<<"res:"<<res<<endl;
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].a>>e[i].b>>e[i].c;
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			Exa[++cex]={n+i+1,j,a[i][j]};
		}
	}
	sort(Exa+1,Exa+cex+1,cmp);
	//cout<<"Cex:"<<cex<<endl;
	for(int i=1;i<=cex;i++){
		tmp[i]=Exa[i];
		//cout<<tmp[i].c<<endl;
	}
	sort(e+1,e+m+1,cmp);
	ll A=0; 
	for(int i=1;i<=m;i++){
		int a=getf(e[i].a),b=getf(e[i].b);
		if(a!=b){
			f[a]=b;
			ed[++cnt]=e[i];
			A+=e[i].c;
		}
	}
	//cout<<"A:"<<A<<endl;
	//cout<<"cnt:"<<cnt<<endl;
	ll res=A;
	for(int s=0;s<(1<<k);s++){
		res=min(res,calc(s));
	}
	cout<<res<<"\n";
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
