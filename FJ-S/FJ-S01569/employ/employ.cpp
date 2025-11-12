#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ans=0;
bool s[505],tf[505];
int jc(int p){
	int a=1;
	for(int i=1;i<=p;i++)
		a*=i;
	return a;
}
void dfs(int x,int y,int z){
	if(x==m){
		ans+=jc(n-y+1);
		return;
	}
	if(y>n)
		return;
	for(int i=1;i<=n;i++){
		if(tf[i]!=1){
			if(s[y]){
				if(c[i]>=z){
					tf[i]=1;
					dfs(x+1,y+1,z);
					tf[i]=0;
				}else{
					tf[i]=1;
					dfs(x,y+1,z+1);
					tf[i]=0;
				}		
			}else{
				tf[i]=1;
				dfs(x,y+1,z+1);
				tf[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(0,1,0);
	cout<<ans;
	return 0;
} 
