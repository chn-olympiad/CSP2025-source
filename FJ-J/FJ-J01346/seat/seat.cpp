#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,y,t,w=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>a[i];
	int w=n*m,t=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=m;++i){
		bool k=0;
		if(i%2==1)
			for(int j=1;j<=n;++j){
				if(a[w]==t){
					k=1,x=i,y=j;					
					break;
				}w--;	
			}
		else
			for(int j=n;j>=1;--j){
				if(a[w]==t){
					k=1,x=i,y=j;					
					break;
				}w--;
			}
		if(k){
			cout<<x<<' '<<y;
			return 0;
		}
	}return 0;
}
