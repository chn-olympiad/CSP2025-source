#include<bits/stdc++.h>
using namespace std;
int ans[15][15],a[225];
bool FLAG=0;
bool cmp(int l,int r){
    return l>r;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,aa;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    aa=a[1];
    sort(a+1,a+n*m+1,cmp);
    int k=1;
    for(int j=1,i=1;j<=m;){
        if(FLAG==0&&i<n){
            ans[i][j]=a[k];
            k++;
            i++;
        }else if(FLAG==0&&i==n){
            ans[i][j]=a[k];
            k++;
            j++;
            FLAG=1;
        }else if(FLAG==1&&i>1){
            ans[i][j]=a[k];
            k++;
            i--;
        }else if(FLAG==1&&i==1){
            ans[i][j]=a[k];
            k++;
            j++;
            FLAG=0;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(aa==ans[i][j])
                cout<<j<<' '<<i;
    return 0;
}
