#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int n,m,a[120],r;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    r=a[0];
    sort(a,a+n*m,cmp);
    int k=0;
    for(int j=0;j<m;j++){
        if((j+1)%2){
            for(int i=0;i<n;i++){
                if(a[k]==r){
                    cout<<j+1<<" "<<i+1;
                    return 0;
                }
                k++;
            }
        }
        else{
            for(int i=n-1;i>=0;i--){
                if(a[k]==r){
                    cout<<j+1<<" "<<i+1;
                    return 0;
                }
                k++;
            }
        }
    }
    return 0;
}
