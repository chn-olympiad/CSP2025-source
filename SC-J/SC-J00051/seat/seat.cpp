#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int b[1000],k;
int cnt;
int p,q;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			b[k++]=a[i][j];
			
		    if(i>1||j>1){
				if(a[i][j]>a[1][1])cnt++;
			}	
			
		}
	}
	p=(cnt-cnt%n)/n+1;
	q=cnt%n;
	if(p%2==1)cout<<p<<" "<<q+1;
	else cout<<p<<" "<<m-q;
}
