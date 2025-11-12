#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    r=a[0];
    int k=0;
    sort(a,a+n*m,cmp);
    for(int i=0;i<n;i++){
        if(i%2==0){
            for(int j=0;j<m;j++){
                if(a[k]==r){
                    cout<<i+1<<" "<<j+1;
                    return 0;
                }
                k++;
            }
        }
        else{
            for(int j=m-1;j>=0;j--){
                if(a[k]==r){
                    cout<<i+1<<" "<<j+1;
                    return 0;
                }
                k++;
            }
        }
    }
    return 0;
}
