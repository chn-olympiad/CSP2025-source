#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c,d=1,fa[100002],m1,m2,fa2[100002];
struct r{
	int u,v,w;
}l[2000002];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int find2(int x){
	if(fa2[x]==x) return x;
	else return fa2[x]=find2(fa2[x]);
}
bool cmp(r x,r y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	//cout<<1<<endl;
	for(int i = 1;i<=n+k;i++){
		fa[i]=i;
		fa2[i]=i;
	}
	//cout<<2<<endl;
	for(int i = 1;i<=m;i++){
		cin>>l[d].u>>l[d].v>>l[d].w;
		d++;
	}
	//cout<<3<<endl;
	sort(l+1,l+m+1,cmp);
	//cout<<4<<endl;
	for(int i = 1;i<=m;i++){
		int a=find(l[i].u),b=find(l[i].v);
		if(a!=b){
			fa[a]=b;
			m1+=l[i].w;
		}
	}
	//cout<<5<<endl;
	for(int i = 1;i<=k;i++){
		cin>>c;
		//cout<<51<<endl;
		for(int j=1;j<=n;j++){
			cin>>l[d].w;
			//cout<<52<<endl;
			l[d].u=j*(i-1)+j+n;
			l[d].v=j;
			//cout<<53<<endl;
			d++;
		}
		//cout<<54<<endl;
	}
	//cout<<6<<endl;
	sort(l+1,l+m+n*k+1,cmp);
	//cout<<7<<endl;
	for(int i = 1;i<=m+n*k;i++){
		int a=find2(l[i].u),b=find2(l[i].v);
		if(a!=b){
			fa2[a]=b;
			m2+=l[i].w;
		}
	}
	//cout<<8<<endl;
	cout<<min(m1,m2);
	return 0;
}
