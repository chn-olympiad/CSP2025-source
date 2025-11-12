#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n,m,fl,x,y,cnt;
int g[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
		cin>>g[i];
	fl=g[1];
	sort(g+1,g+n*m+1,cmp);
	for(int i=1;i<=n;++i){
		if(i%2==0){
			for(int j=m;j>=1;--j){
				cnt++;
				if(g[cnt]==fl){
					x=i;
					y=j;
				}
			}
		}
		else{
			for(int j=1;j<=m;++j){
				cnt++;
				if(g[cnt]==fl){
					x=i;
					y=j;
				}
			}
		}
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}