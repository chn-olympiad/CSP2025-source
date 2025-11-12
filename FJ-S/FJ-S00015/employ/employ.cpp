#include<bits/stdc++.h>
using namespace std;
long long a,b,c[505],d[505],e[505],f=0;
string s;
void dfs(int x,int y,int z){
	if(x==a+1){
		if(y>=b){
			f++;
			f=f%998244353;
		}
		return ;
	}
	if(b-y>a-x+1){
		return ;
	}
	if(y==b){
		long long g=1;
		for(int i=1;i<=a-x+1;i++){
			g*=i;
			g=g%998244353;
		}
		f+=g;
		f=f%998244353;
		return;
	}
	for(int i=1;i<=a;i++){
		if(e[i]==0){
			e[i]=1;
			if(s[x-1]=='0'){
				dfs(x+1,y,z+1);
			}else{
				if(d[i]>z){
					dfs(x+1,y+1,z);
				}else{
					dfs(x+1,y,z+1);
				}
			}
			e[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	cin>>s;	

	for(int i=1;i<=a;i++){
		cin>>d[i];
	}
	dfs(1,0,0);
	cout<<f;
} 
