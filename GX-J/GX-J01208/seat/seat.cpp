#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005][10005],b[10005],x;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        cin>>a[i][j];
        b[i]=a[i][j];
        }
    }
    x=a[1][1];
    if(x==100){
		cout<<1<<" "<<1;
	}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i+j]>=b[i+j-1]){
			    b[i+j-1]=b[j+i];
		    }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[i][j]=b[i+j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==x){
			    cout<<i<<" "<<j;
		    }
        }
    }
    
    return 0;
    }
