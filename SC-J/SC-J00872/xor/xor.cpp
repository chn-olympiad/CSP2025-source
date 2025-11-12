#include<bits/stdc++.h>
using namespace std;
int n,m,c,maxx=0;
int d[100005][25];
int ans[25];
int use[100005];
void in(int i,int x){
	int s=1;
	while(x!=0){
		d[i][s]=x%2;
		x/=2;
		s++;
	}
	return;
}
void dfs(int k,int h){
	bool b=0;
	maxx=max(maxx,h);
	if(use[k]>0 && use[k]>h) return;
	use[k]=h;
	if(k>n) return;
	for(int i=k;i<=n;i++){
		for(int j=i;j<=n;j++){
			b=1;
			for(int l=1;l<=21;l++){
				if((d[j][l]-d[i-1][l])%2!=ans[l]){
					b=0;
					break;
				}
			}
			if(b){
				dfs(j+1,h+1);
				break;
			}
		}
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	int z=1;
	while(m!=0){
		ans[z]=m%2;
		m/=2;
		z++;
	}
	for(int i=1;i<=n;i++){
		cin>>c;
		in(i,c);
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=21;j++){
			d[i][j]+=d[i-1][j];
		}
	}
	if(d[n][1]==n){
		cout<<n/2<<endl;
		return 0;
	}
	dfs(1,0);
	cout<<maxx;
	return 0;
} 