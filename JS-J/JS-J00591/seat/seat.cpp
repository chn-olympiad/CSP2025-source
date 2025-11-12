#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+5;
int n,m,k;
bool flag;
int a[maxn];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i*m+j];
        }
    }
    k=a[0];
    sort(a,a+(n*m),cmp);
    for(int i=0;i<m;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                if(a[i*n+j]==k){
                    cout<<i+1<<" "<<j+1;
                    flag=1;
                    break;
                }
            }
        }
        else{
            for(int j=0;j<n;j++){
                if(a[i*n+j]==k){
                    cout<<i+1<<" "<<m-j;
                    flag=1;
                    break;
                }
            }
        }
    }
    return 0;
}
