#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,num=0,a[10000][10000]={0};
	cin>>n>>m>>k;
	while(m--){
		int a1,b,c;
		cin>>a1>>b>>c;
		a[a1][b]=a[b][a1]=c;
	}
	while(n--){
		int a1,x;
		cin>>a1;
		for(int i=1;i<=n;i++){
			cin>>x;
			a[n+i][i]=a[i][i+n]=x+a1;
		}
	}
	for(int i=1;i<=n;i++){
		int bj=0,mi=0;
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			if(a[i][j]!=0){
			}
		}
		if(bj==0){
			i--;
		}else{
			i=bj;
		}
	}
	return 0;
}
