#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[105],n,m,c,r;
bool f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	c=n*m;
	for(int i=1;i<=c;i++)cin>>b[i];
	r=b[1];
	sort(b,b+c+1);
	int s=c;
	for(int i=1;i<=n;i++){
		if(f==1){
			for(int j=m;j>=1;j--){
				if(b[s]==r){
					cout<<i<<" "<<j;
					return 0;
				}else{
					a[i][j]=b[s];
					s--;	
				}
			}
			f=0;
		}else{
			for(int j=1;j<=m;j++){
				if(b[s]==r){
					cout<<i<<" "<<j;
					return 0;
				}else{
					a[i][j]=b[s];
					s--;	
				}
			}
			f=1;
		}
	}
	return 0;
}
