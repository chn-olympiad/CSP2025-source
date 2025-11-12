#include<bits/stdc++.h>
#include<con> 
using namespace std;
int n,m,k,c;
vector<int>a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int v,u,w,ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>v,u,w;
		ans+=w;
	}
	cin>>c;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	cin>>c;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	if(u+v+w>-100000)cout<<ans-10<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
