#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[110];
int v[1010][1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int num=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,z=1;
	int f=0;
	while(z<=n*m){
		if(x==0){
			f=0;
			y++;
			x=1;
		}
		if(x>n){
			f=1;
			x=n;
			y++;
		}
		v[x][y]=a[z];
		z++;
		if(f==1)
			x--;
		else if(f==0) x++;
		
	}
	//~ for(int i=1;i<=n;i++){
		//~ for(int j=1;j<=m;j++){
			//~ cout<<v[i][j]<<" ";
		//~ }
		//~ cout<<endl;
	//~ }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(v[i][j]==num){
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
