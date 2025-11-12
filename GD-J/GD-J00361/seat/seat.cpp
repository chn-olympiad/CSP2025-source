#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[102][102],d[10001];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>d[i];
	int tgt=d[1],t=0;
	sort(d+1,d+n*m+1,cmp); 
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				t++;
				if(d[t]==tgt){
					cout<<i<<" "<<j;
					return 0;
				}
			}	
		}else{
			for(int j=n;j>=1;j--){
				t++;
				if(d[t]==tgt){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
} 
