#include<bits/stdc++.h>
using namespace std;
const int N=1e7+1; 
long long a[N],f[N],v[N],x=1,n,m;
void dfs(int x){
	if(x>=n+1){
		for(int i=1;i<=n;i++){
			cout<<f[i]<<" ";
		}cout<<endl;
		return ;
	}for(int i=1;i<=2*n;i++){
		if(v[a[i]]==0){
			f[x]=a[i];
			v[a[i]]=1;
			dfs(x+1);
			v[a[i]]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin); 
	freopen("employ.out","w",stdout); 

	cin>>n>>m;
	string a;
	cin>>a; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i]; 
	}dfs(1);
	return 0;
} 
