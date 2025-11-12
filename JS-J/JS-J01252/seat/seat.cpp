#include<bits/stdc++.h>
using namespace std;
int a[11][11],x[101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,w,y=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>x[i];
		if(i==1){
			w=x[i];
		}
	}
	sort(x+1,x+n*m+1);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(x[n*m-y+1]==w){
					cout<<i<<" "<<j;
					return 0;
				}
				y++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				if(x[n*m-y+1]==w){
					cout<<i<<" "<<j;
					return 0;
				}
				y++;
			}
		}
	}
	cout<<-1;
    return 0;
}
