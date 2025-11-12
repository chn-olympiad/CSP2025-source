#include<bits/stdc++.h>
using namespace std;
long long n,m,r,len,x=0,y=0;
long long a[5000],b[5000][5000];
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    len=n*m;
    for(int i=0;i<len;i++){
        cin>>a[i];
    }
    r=a[0];
    sort(a,a+len);
    for(int i=len-1;i>=0;i--){
        b[x][y]=a[i];
        if(y%2==0){
            x++;
            if(x==n){
                x--;
                y++;
            }
        }else{
            x--;
            if(x==-1){
                x++;
                y++;
            }
        }

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j]==r){
                cout<<j+1<<" "<<i+1;
                return 0;
            }
        }
    }
    return 0;
}
