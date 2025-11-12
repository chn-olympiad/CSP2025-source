#include<bits/stdc++.h>
int a[15][15],b[105];
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int x=0,m,n,s;
	cin>>n>>m;
	for(int i=0;i<=n*m-1;i++){
		cin>>b[i];
		x++;
	}
	s=b[0];
	sort(b,b+x);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				x--;
				a[j][i]=b[x];
			}
		}
		else{
			for(int j=m;j>=1;j--){
				x--;
				a[j][i]=b[x];
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
			if(a[i][j]==s)
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
}
