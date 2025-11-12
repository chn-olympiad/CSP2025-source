#include<bits/stdc++.h>
using namespace std;
bool cmp(int b1,int b2){
	return b1>=b2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b[200]={};
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>b[i];
	int x=b[0];
	sort(b,b+n*m+1,cmp);
	for(int i=0;i<m*n;i++)cout<<b[i]<<' ';
	int cnt=-1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
					cnt++;
					if(b[cnt]==x){
						cout<<i<<' '<<j<<' ';
						return 0;
					}	
			}		
		}else{
			for(int j=n;j>0;j--){
				cnt++;
				if(b[cnt]==x){
					cout<<i<<' '<<j<<' ';
					return 0;
					}	
			}
		}
	}
	return 0;
}
