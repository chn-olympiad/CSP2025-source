#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int main (){
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	int n,m;
	cin>>
	for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            cin>>a[i][j];

        }
	}
	for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
               if(a[i][j]<a[1][1]){
               cout<<n+1<<m+1;
            }
        }
	}
	return 0;
}
