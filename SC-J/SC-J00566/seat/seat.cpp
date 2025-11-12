#include<bits/stdc++.h>
using namespace std;

int a[1005],n,m,t,x=1,y=1,b[105][105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[1];
    sort(a,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(t==a[i]){
   		    t=i;
   		    break;
	    }
    }
    t=n*m-t+1;
    int q=1;
    for(int k=1;k<=m;k++){
        for(int i=1;i<=n;i++){
    	    b[x][y]=q;
    	    q++,x++;
	    }
	    x--,y++;
	    for(int i=1;i<=n;i++){  
			b[x][y]=q;
			q++,x--;
	    }
	    x++,y++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		    if(b[i][j]==t){
		    	cout<<j<<" "<<i;
		    	return 0;
			}
	    }
	}
    return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
2 2
98 99 100 97
2 2
99 100 97 98
*/