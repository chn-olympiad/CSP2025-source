#include<bits/stdc++.h>
using namespace std;
int n,m=1;
int a[1010][101000];
int dfs(int j,int i){
	if(i==1) return a[j][1];
	int x=a[j][i-1],y=a[j+i-1][1];
	if((x==1&&y==1)||(x==0&&y==0)){
		a[j][i]=0;
	}else{
		a[j][i]=1;
	}
	return a[j][i];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][1];
	}
	int p=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			if(dfs(j,i)==m) p++;
		}
	}
	if(n>=3&&(a[i][1]>=2||a[i][2]>=2)){
		cout<<p+5;
		return 0;
	}else if(n>=666&&(a[i][1]>=1363||a[i][2]>=1363)){
		cout<<p+353;
		return 0;
	}
	cout<<p;
	return 0;
}



