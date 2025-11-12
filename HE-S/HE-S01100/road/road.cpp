#include<bits/stdc++.h>
using namespace std;
struct manba{
	int need;
	int k[10000];
	
};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a[m][3]={0};
	for(int i=0;i<m;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		
	}
	manba b[k];
	for(int i=0;i<=k;i++){
		cin>>b[i].need;
		for(int j=0;j<n;j++){
			cin>>b[i].k[j];
		}
	}
	for(int i=0;i<m;i++){
		if(a[i][2]>b[i].need+b[i].k[a[i][1]-1]+b[i].k[a[i][0]-1]){
			a[i][2]=b[i].need+b[i].k[a[i][1]-1]+b[i].k[a[i][0]-1];
		} 
	}                                        
	int ans=0;
	for(int i=0;i<m;i++){
		ans+=a[i][2];
	}
	cout<<ans;                
	return 0;
}
