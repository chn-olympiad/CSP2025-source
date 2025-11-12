#include<bits/stdc++.h>
using namespace std;
const int N=10*10+5;
int n,m,g=1;
int man[N],xh[15][15];
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int u=n*m;
	for(int i=1;i<=u;++i)
		scanf("%d",&man[i]);
	int a=man[1];
	sort(man+1,man+u+1,cmp);
	for(int i=1;i<=n;++i){
		if(i%2==1){
			for(int j=1;j<=m;++j){
				xh[i][j]=man[g];
				g++;
			}
		}
		else{
			for(int j=m;j>=1;--j){
				xh[i][j]=man[g];
				g++;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(xh[i][j]==a){
				cout<<i<<" "<<j;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//石室欢迎你 