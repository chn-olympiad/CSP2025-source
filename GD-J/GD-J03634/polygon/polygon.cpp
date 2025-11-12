#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long s,js;
void dfs(int k,int q,int h){
	if(k==n+1&&q>=3){
		if(s>a[h]*2){
			js++; 
			return ;
		}
	}else{
		if(k==n+1)return ;	
		s+=a[k];
		dfs(k+1,q+1,k);
		s-=a[k];
		dfs(k+1,q,h);
	} 

} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
    dfs(1,0,0);
    cout<<js%998244353 ;
	return 0;
}
