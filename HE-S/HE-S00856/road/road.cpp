#include<bits/stdc++.h>
using namespace std;
long long n,m,k,z=1,ans=0,cnt=0;
long long pa[1005];
long long q;
long long aa[1005];
struct node{
	int a,b,w;
}str[100000005];
bool cmp(node aaa,node bbb){
	return aaa.w<bbb.w;
}
int find(int x){
	if(x==pa[x]){
		return x;
	}
	return pa[x]=find(pa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>str[i].a>>str[i].b>>str[i].w;
		z++;
	}
	for(int i=1;i<=k;i++){
		cin>>q;
		for(int j=1;j<=n;j++){
			cin>>aa[j];
		}
		for(int j=1;j<=n;j++){
			for(int y=j+1;y<=n;y++){
				str[z].a=j;
				str[z].b=y;
				str[z].w=q+aa[y]+aa[j];
				z++;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		pa[i]=i;
	}
	sort(str+1,str+z,cmp);
	for(int i=1;i<z;i++){
		if(find(str[i].a)!=find(str[i].b)){
			pa[find(str[i].a)]=str[i].b;
			ans+=str[i].w;
			cnt++;
		}
		if(cnt==n-1){
			cout<<ans;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
