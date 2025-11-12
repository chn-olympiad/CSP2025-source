#include<bits/stdc++.h>
using namespace std;
int n,m;
int x=1,y=1;

int a[10005];
int main()
{
    freopen("seat.in","r",stdin);
    froopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int xiao=a[1];
    sort(a+1,a+1+n*m);

    for(int i=n*m;i>=1;i--){
        if(a[i]==xiao){
            cout<<x<<" "<<y;
            return 0;
        }
        if(x%2==0&&(y-1)>=1){
            y--;
        }
        else if(x%2==0&&(y-1)<1){
            x++;
        }
        else if(x%2==1&&(y+1)<=m){
            y++;
        }
        else if(x%2==1&&(y+1)>m){
            x++;
        }
    }

    return 0;
}
