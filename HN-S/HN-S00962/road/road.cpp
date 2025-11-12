#include<bits/stdc++.h>
using namespace std;
struct str{
	int x,y,z;
}s[1010101];
int n,m,k,lt,ans;
int fa[1010101];
int b[10][1010101];
bool cmp(str t1,str t2){
	return t1.z<t2.z;
}
int find(int level){
	if(fa[level]!=level)fa[level]=find(fa[level]);
	return fa[level];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	lt=n;
	for(int i=1;i<=m;i++){
		cin>>s[i].x>>s[i].y>>s[i].z;
	}
	sort(s+1,s+m+1,cmp);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	} 
	for(int i=1;i<=k;i++){
		scanf("%d",b[i][0]);
		ans+=b[i][0];
		for(int j=1;j<=n;j++){
			scanf("%d",b[i][j]);
			if(b[i][j]==0){
				if(find(i)!=find(j)){
					fa[find(i)]=find(j);
					lt--;
					ans+=b[i][j];
				}
			}
			
		}
	}
	for(int i=1;i<=m;i++){
		if(lt==1){
			printf("%d",ans);
			return 0;
		}
		int tx=find(s[i].x),ty=find(s[i].y);
		cout<<tx<<' '<<ty<<endl;
		if(tx!=ty){
			fa[tx]=ty;
			lt--;
			ans+=s[i].z;
		}
	}
	printf("%d",ans);
	return 0;
}
