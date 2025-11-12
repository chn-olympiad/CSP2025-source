#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	int arr[n+1][n+1]={};
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		arr[a][b]=c;
		arr[b][a]=c;
		ans+=c;
	}cout<<ans;
} 
