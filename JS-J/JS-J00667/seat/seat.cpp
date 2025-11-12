#include <bits/stdc++.h>
using namespace std;
int m,n,a[100][100],s[2200],sss=1,cou=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){

        cin>>s[i];

    }
    sss=s[1];
    sort(s+1,s+m*n+1,cmp);

        for(int i=1;i<=m*n;i++){

            if(s[i]==sss){
                int x=(i+m-1)/m;
                if(x%2==1){
                    cout<<x<<' '<<m-x*m+i;
                    break;
                }
                else{
                    cout<<x<<' '<<x*m-i+1;
                    break;
                }
            }
        }

    return 0;
}
