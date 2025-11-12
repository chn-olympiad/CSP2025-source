#include <bits/stdc++.h>
using namespace std;
int n,m,c=1,r=1;
int a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int s=0;
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]){
            s++;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s!=0){
                s--;
            }else if(s==0){
                break;
            }
            r++;
        }
        if(s==0){
            break;
        }
        r=1;
        c++;
    }
    return 0;
}
