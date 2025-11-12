#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000];
int x,k;
bool cmp(int u,int v){
    return u>v;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int g=n*m;
    cin>>x;
    a[1]=x;
    for(int i=2;i<=g;i++){
        cin>>a[i];
    }
    sort(a+1,a+g+1,cmp);
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                k++;
                if(a[k]==x){
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
            }
        }if(j%2==0){
            for(int i=n;i>=1;i--){
                k++;
                if(a[k]==x){
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
            }
        }
    }return 0;
}
