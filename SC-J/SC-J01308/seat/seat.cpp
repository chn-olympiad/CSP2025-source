#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],g[1010][1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,ans;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	    cin>>a[i];
	ans=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int i=1,j=1,opt=1;///opt1向下走，opt2向上走 
	while(x<=n*m){
		if(opt==1){//向下走 
			g[i][j]=a[x];
			x++,i++;
			if(i>n){
				i=n;
				j++;
				opt=2;
			}
		}
		else if(opt==2){//向上走 
			g[i][j]=a[x];
			x++,i--;
			if(i<1){
				i=1;
				j++;
				opt=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]==ans){
				cout<<j<<" "<<i;
				return 0;
			}
		}
    }
	
} 