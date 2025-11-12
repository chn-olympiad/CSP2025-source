#include<bits/stdc++.h>
using namespace std;
int a[200],ans[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x,p=0;
	cin>>x;
	a[1]=x;
	for(int i=2;i<=m*n;i++) cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x) p=i;
	}
	//cout<<p<<'\n';
	int k=1,i=1,j=1;
	bool dir=0;//0下 1上 
	while(k<=n*m){
		ans[i][j]=k;
		k++;
		if(i==1&&dir){
			j++;
			dir=0;
		}else if(i==n&&!dir){
			j++;
			dir=1;
		}else{
			if(dir==0) i++;
			else i--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==p) return cout<<j<<' '<<i,0;	
		}
	}
	return 0;
}
//i行 j列 