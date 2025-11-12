#include<bits/stdc++.h>
using namespace std;
const int N=15;
int g[N][N];
int a[N*N],n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int i=1,j=1;
	for(int k=1;k<=n*m;k++){
		g[i][j]=a[k];
		if(j%2==1){
			i++;
		}else if(j%2==0){
			i--;
		}
		if(i>n||i<1){
			j++;
			if(j%2==0) i=n;
			else i=1;
		}
	}
	int ansi,ansy;
	bool st=false;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]==r){
				ansi=i;
				ansy=j;
				st=true;
				break;
			} 
		}
		if(st){
			break;
		}
	}
	cout<<ansy<<" "<<ansi<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
