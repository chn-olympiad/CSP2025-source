#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int a[10005]={0},a1[105][105]={0};
    cin>>n>>m;
    int x=n*m,y,k=1;
    for(int i=1;i<=x;++i){
        cin>>a[i];
    }
    y=a[1];
    sort(a+1,a+x+1,cmp);
    for(int i=1;i<=n;++i){
        if(i%2!=0){
            for(int j=1;j<=n;++j){
                a1[j][i]=a[k];
                k++;
                if(a1[j][i]==y){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }else{
            for(int j=n;j>=1;--j){
                a1[j][i]=a[k];
                k++;
                if(a1[j][i]==y){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
