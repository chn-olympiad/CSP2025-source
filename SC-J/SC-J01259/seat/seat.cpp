#include<bits/stdc++.h>
using namespace std;
int n,m;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int f[40000]={0};
	cin>>n>>m;
	int temp[2]={1,1};
	for(int i=1;i<=n*m;i++){
		cin>>f[i];
	}
	int v=f[1];
	sort(f+1,f+m*n+1,cmp);
	int w[200][200]={0};
	for(int i=1;i<=n*m;i++){
		int q=temp[0];
		w[temp[0]][temp[1]]=f[i];
		if(temp[1]==m&&temp[0]%2==1){
			temp[0]++;
		}
		if(temp[1]==1&&temp[0]%2==0) {
			temp[0]++;
		}
		if(q==temp[0]){
			if(temp[0]%2==1){
				temp[1]++;
			}else{
				temp[1]--;
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;i<=m;i++){
			if(v==w[i][j]){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}