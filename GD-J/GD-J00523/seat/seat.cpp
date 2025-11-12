#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int const maxn=100;
int g[maxn+1];
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&g[i]);
	}
	int pm=1;
	for(int i=2;i<=n*m;i++){
		if(g[i]>g[1]){
			pm++;
		}
	}
	int r=1;
	int c=1;
	for(int i=1;i<pm;i++){
		if((r==n&&(c&1))||(r==1&&(!(c&1)))){
			c++;
			continue;
		}
		if(c&1){
			r++;
		}
		else{
			r--;
		}
	}
	printf("%d %d",c,r);
	
	
	
	return 0;
}
