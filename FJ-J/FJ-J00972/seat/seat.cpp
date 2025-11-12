#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,a[N],csk,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}	
	csk=a[1];
	sort(a+1,a+1+n*m,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i]<<' ';
//	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[(i-1)*n+j]==csk){
				if(i%2==1){
					cout<<i<<' '<<j;
					return 0;
				}
				else{
					cout<<i<<' '<<n-j+1;
					return 0;
				}
			}
		}
	}
}
