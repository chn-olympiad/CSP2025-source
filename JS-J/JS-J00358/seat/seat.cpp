#include<bits/stdc++.h>
using namespace std;
bool cmp(int l,int r){
     return l>r;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[1010]={};
    int cnt=0;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    cnt=a[1];
    int aa=0;
    sort(a+1,a+n*m+1,cmp);
    int b[100][100]={};
    int l=1,r=n;
    for(int i=1;i<=m;i++){
        if(l<r){
           for(int j=l;j<=r;j++){
                b[j][i]=a[++aa];
                if(b[j][i]==cnt){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }else{
            for(int j=l;j>=r;j--){
                b[j][i]=a[++aa];
                if(b[j][i]==cnt){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        l=n-l+1;
        r=n-r+1;
    }
    return 0;
}
