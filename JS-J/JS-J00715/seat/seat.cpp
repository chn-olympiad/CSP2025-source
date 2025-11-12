#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int c[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int me=0;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	me=c[1];
	int now=0;
	sort(c+1,c+1+n*m,cmp);
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;j++){
			++now;
			if(c[now]==me){
				cout<<m<<' ';
				if(i%2==0){
					cout<<n-j+1;
				}else{
					cout<<j;
				}
				return 0;
			}
		}
	}
	return 0;
}
