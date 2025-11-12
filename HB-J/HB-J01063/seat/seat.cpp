#include<bits/stdc++.h>
using namespace std;
int n,m,num=0;
int a[101],b[101][101]={};
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
                cin>>a[i];
            }
    num=a[0];
    sort(a,a+n*m+1,cmp);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            b[j][i]=a[i*j];
            if(b[j][i]=num){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
