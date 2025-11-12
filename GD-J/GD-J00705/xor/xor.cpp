#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
int n,k;
int a[MAXN][MAXN];
struct st{
	int x,y;
}r[10005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int maxx;
	for(int i=1;i<=n;i++){
		cin>>a[1][i];
		if(a[1][i]==k){
			maxx=1;
		}		
	}
	int v=2;
	int cnt=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-v+1;j++){
			a[i][j]=a[i-1][j]^a[1][i-1+j];
			if(a[i][j]==k){
				r[cnt].x=i;
				r[cnt].y=j;
				cnt++;
				maxx=v;
			}
		}
		v++;
	}
	cout<<maxx;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
