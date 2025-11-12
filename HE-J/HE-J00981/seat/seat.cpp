#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("seat1.in","r",stdin);
freopen("seat1.out","w",stdout);
int n,m;
cin>>n>>m;
int v[n][m],k[n*m];
for(int i=0;i<n*m;i++) cin>>k[i];
int c=k[0],u=n*m-1;
sort(k,k+n*m);
bool t=true;
for(int i=0;i<n;i++){
        if(t){
           	for(int j=0;j<m;j++){
                 v[i][j]=k[u];
                 u--;
           	}
           	t=false;
        }else{
            for(int j=m-1;j>=0;j--){
             v[i][j]=k[u];
                 u--;
            }
            t=true;
        }
	}
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		if(c==v[i][j]){
           cout<<i+1<<" "<<j+1;
           return 0;
		}
	}
}
}

