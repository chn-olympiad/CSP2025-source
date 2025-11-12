#include <bits/stdc++.h>
using namespace std;
const int N=100;
int a,b,c[N][N],w;
int s[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int v,m;
	cin>>v>>m;
	for(int i=0;i<v*m;i++){
		cin>>s[i];
	}
	int l=v*m,j=s[0],p=v*m;
	sort(s,s+p);
	p-=1;
	for(int i=0;i<v;i++){
		int u=0;
		if(i%2==1){
			for(u=m-1;u>=0;u--){
				if(s[p]==j){
					cout<<u+1<<' '<<i+1;
					return 0;
				}
				c[u][i]=s[p];
				p-=1;
			}
		}
		else{
			for(u=0;u<m;u++){
				if(s[p]==j){
					cout<<i+1<<' '<<u+1;
					return 0;
				}
				c[u][i]=s[p];
				p-=1;
			}
		}
	}
}
	 