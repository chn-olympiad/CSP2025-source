#include <bits/stdc++.h>

using namespace std;
const int N=110;
int n,m,a[N],se[12][12],r;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+1+n*m,cmp);
    int id=1,ans1=0,ans2=0;
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                se[i][j]=a[id];
                if(a[id]==r)ans1=j,ans2=i;
                id++;
            }
        }else{
            for(int i=n;i>=1;i--){
                se[i][j]=a[id];
                if(a[id]==r)ans1=j,ans2=i;
                id++;
            }
        }
    }
    cout<<ans1<<" "<<ans2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
