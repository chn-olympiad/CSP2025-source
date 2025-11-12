//GZ-S00345 北京八中贵阳分校 田小民
#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,a[10000+20][10000+20],s;
struct node{//道路 
	int u,v,w;
}e[1000000+10];
struct city{//城镇化 
	int q,l[1000+10];
}b[20];
void Op(){
	for(int i=0;i<n;i++){
		if(e[0].w>b[0].q+b[0].l[i]){
			ans+=b[0].q+b[0].l[i];
			while(e[m].u==i){a[e[m].u][i]=1;}
			while(e[m].v==i){a[e[m].v][i]=1;}
		}
	}
	ans+=e[0].w;
	a[e[0].u][e[0].v]=1;
	e[0].w=INT_MAX;
}
bool cmp(node x,node y){
	return x.w<y.w;
}
bool bmp(city x,city y){
	return x.l<y.l; 
}
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=0;i<k;i++){
		cin>>b[i].q;
		for(int j=1;j<=n;j++){
			cin>>b[i].l[j];
		}
	}
	sort(e,e+n,cmp);
	sort(b,b+k,bmp);
	Op();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j])	s++;
		}
	}
	if(s==m+1||s==m||s==m-1) {cout<<ans;return 0;}
	else{
		while(s!=m||s!=m-1||s!=m+1) {sort(e,e+n,cmp);Op();}
	} 
	cout<<ans<<endl;
	return 0;
}
