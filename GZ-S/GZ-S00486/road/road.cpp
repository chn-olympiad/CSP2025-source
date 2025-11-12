//GY-S40086 贵阳市第一中学 陶昱泽
#include<bits/stdc++.h>
using namespace std;
int d[10000][10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a,b,c;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		d[a][b]=c;
		d[b][a]=c;
	}
	if(k>0){
		for(int i=1;i<=k;i++){
			cin>>a;
			if(a){
			return 0;
		}
	}
		cout<<"0";
	}else{
		
	}
	return 0;
} 
