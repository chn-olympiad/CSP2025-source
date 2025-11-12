#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int s=0;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		s+=u;
	}
	cout<<s<<endl;
	return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int s=0;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		s+=u;
	}
	cout<<s<<endl;
	return 0;
}
*/
