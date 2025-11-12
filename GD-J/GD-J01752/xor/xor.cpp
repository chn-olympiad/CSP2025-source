#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500005],d[500005],e=0,i[500005];
void dfs(long long f,long long g){
	if(i[f]>=g)return ;
	i[f]=g;
	if(f==a+1){
		e=max(e,g);
		return ;
	}
	for(int z=f;z<=a;z++){
		for(int y=z;y<=a;y++){
			if((d[y]^d[z-1])==b){
				dfs(y+1,g+1);
			}
		}
	}
	e=max(e,g);
	return ;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b>>c[1];
	d[1]=c[1];
	d[0]=0;
	i[1]=-1;
	i[0]=-1;
	for(int z=2;z<=a;z++)cin>>c[z],d[z]=d[z-1]^c[z],i[z]=-1;
	dfs(1,0);
	cout<<e;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
