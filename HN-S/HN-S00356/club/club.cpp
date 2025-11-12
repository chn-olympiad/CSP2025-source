#include<bits/stdc++.h>
using namespace std;
long long a[100000][3];
int n,m,MAX=-1;
int b[4];
void dfs(int x,int count){
	if(x==m+1){
		MAX=max(MAX,count);
		return;
	}
	for(int i=1;i<=3;i++){
		while(b[i]>=m/2)i++;
		b[i]++;
		dfs(x+1,count+a[x][i]);
		b[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		MAX=0;
		cin>>m;
		for(int j=1;j<=m;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
		}
		dfs(1,0);
		cout<<MAX<<endl;
	}
}


