#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    return a>b;
}
int n,m,a[500],sum=0,t,ans=0;
bool fl=true;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    t=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==t){
            ans=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            for(int j=1;j<=m;j++){
                sum++;
                if(sum==ans){
                    cout<<i<<' '<<j;
                    fl=false;
                    break;
                }
            }
        }
        else if(i%2==0){
            for(int j=m;j>=1;j--){
                sum++;
                if(sum==ans){
                    cout<<i<<' '<<j;
                    fl=false;
                    break;
                }
            }
        }
        if(fl==false){
            break;
        }
    }
    return 0;
}

