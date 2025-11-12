#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,sum,z;
string s,s1;
long long a[186];
long long b[186];
long long c[20][20];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>x;
        if(i==1){
            z=x;
        }
        a[x]++;
    }
    for(int i=100;i>=1;i--){
        if(a[i]==1){
            b[++y]=i;
        }
    }
    for(int i=1;i<=n;i++){
        if(i%2){
            for(int j=1;j<=m;j++){
                c[i][j]=b[++sum];

            if(b[sum]==z){
                cout<<i<<' '<<j<<endl;
                return 0;
            }
            }
        }else{
            for(int j=m;j>=1;j--){
                c[i][j]=b[++sum];

            if(b[sum]==z){
                cout<<i<<' '<<j<<endl;
                return 0;
            }
            }
        }
    }
    
 return 0;
}



