#include<bits/stdc++.h>
using namespace std;
int n,a[5050];
long long ant=0;
bool b[5050];
void dfs(int ma,int z,int g,int s){
	if(z>ma*2&&g>=3){
		ant++;
		ant%=998244353;
	} 
	for(int i=s;i<n;i++){
		int z1=z+a[i];
		int m=max(ma,a[i]);
		if(b[i]==0){
			b[i]=1;
			dfs(m,z1,g+1,i);
			b[i]=0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ant;
	return 0;
} 