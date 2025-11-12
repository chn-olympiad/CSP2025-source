#include<bits/stdc++.h>
using namespace std;
int cmp(long long a,long long b){
    return a>=b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,x=1,y=1,cnt=1;
    cin>>n>>m;
    long long k[n*m+5],a[n+2][m+2];
    for(long long i=1;i<=m*n;i++){
        cin>>k[i];
    }
    long long t=k[1];
    sort(k+1,k+1+n*m,cmp);
    while(1){
        a[x][y]=k[cnt];
        if(a[x][y]==t){
            cout<<x<<' '<<y;
            break;
        }
        cnt++;
        if(x%2&&y!=n) y++;
        else if(x%2&&y==n||x%2==0&&y==1) x++;
        else if(x%2==0&&y!=1) y--;
    }
	return 0;
}

