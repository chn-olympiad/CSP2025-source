#include<bits/stdc++.h>
using namespace std;
int a[20][10010],b[10010];
struct xl{
	int x,y,z;
}v[1001000];
bool top(xl n,xl m){
	return n.z<m.z;
}
int fun(int x){
	if(b[x]==x)return b[x];
	else	return b[x]=fun(b[x]);
}
void sweap(int x,int y){
	int fx=fun(x);
	int fy=fun(y);
	b[fx]=fy;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int s=0;
    for(int i=1;i<=m;i++){
    	cin>>v[i].x>>v[i].y>>v[i].z;
    	
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=i;
	}
	sort(v+1,v+n+1,top);
	for(int i=1;i<=m;i++){
		if(fun(v[i].x)!=fun(v[i].y)){
			sweap(v[i].x,v[i].y);
			s+=v[i].z;
		}
	}
	cout<<s;
    return 0;
}
