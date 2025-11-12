#include <bits/stdc++.h>
using namespace std;
int t,n,sum,x[3][20001],a,b,c;
bool f[3][20001];
int main(){
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>x[1][j]>>x[2][j]>>x[3][j];
		}
		int maxx1=0,maxx2=0,maxx3=0,a1=0,b1=0,c1=0;
		for(int j=1;j<=n;j++){
			if(x[1][j]>maxx1){
				maxx1=x[1][j];
				x[1][j]=false;
				x[1][a1]=true;
				a1=j;
			} 
			if(x[2][j]>maxx2){
				maxx2=x[2][j];
				x[2][j]=false;
				x[2][b1]=true;
				b1=j;
			}
			if(x[3][j]>maxx3){
				maxx2=x[3][j];
				x[3][j]=false;
				x[3][c1]=true;
				c1=j;
			}
			sum+=max(maxx1,max(maxx2,maxx3));
		}
		cout<<sum<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
