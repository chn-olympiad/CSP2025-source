#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s[11][11],r;
bool hhh(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	r=a[0];
	int d=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				s[i][j]=d;
				d++;
			}
			else{
				s[i][j]=d;
				d--;
			}
		}
		d+=n;
		if(i%2==1){
			d--;
		}
		else
			d++;
	}
	sort(a,a+n*m,hhh);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(r==a[s[i][j]]){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
}
