#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c,tot;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>c;
	a[1]=c;
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				tot++;
				if(a[tot]==c){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				if(a[++tot]==c){
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
			}
		}
	}
	return 0;
}