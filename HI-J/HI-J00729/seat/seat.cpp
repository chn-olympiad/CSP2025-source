#include<bits/stdc++.h>
using namespace std;
int sz[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>sz[i];
	}
	R=sz[0];
	int h=0,l=0,szxb=n*m-1; 
	sort(sz,sz+n*m);
	for(int l=1;l<=m;l++){
		if(l%2==1){
			for(int h=1;h<=n;h++){
				if(sz[szxb]==R){
					cout<<l<<' '<<h;
					return 0;
				}
				szxb--;
			}
		}
		else{
			for(int h=n;h>0;h--){
				if(sz[szxb]==R){
					cout<<l<<' '<<h;
					return 0;
				}
				szxb--;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
