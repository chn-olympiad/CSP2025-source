#include<bits/stdc++.h>
using namespace std;
int n,a[5100];
long long s; 
void dfs(int x,int y,int z){
	for(int i=y+1;i<=n;i++){
		if(a[i]<x&&z>=2){
			s++;
		}	
		dfs(x+a[i],i,z+1);
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
	for(int i=1;i<=n;i++){
		dfs(a[i],i,1);
	}
	cout<<s%998244353;
    return 0;
}
