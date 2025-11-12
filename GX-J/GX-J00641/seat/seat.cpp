#include<bits/stdc++.h>
using namespace std;

void into()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
}

int main()
{
    into();
    int n,m; cin >>n >>m;
    int a[n*m],s[n*m],maps[n][m]={{0}};
    for(int i=0;i<n*m;i++) cin >>a[i];
    for(int i=0;i<n*m;i++) s[i]=a[i];
    sort(a,a+n*m,greater<int>());
    int x=0,y=0;
    bool flag=0;
    for(int k=0;k<n*m;k++){
        maps[x][y]=a[k];
        cout <<x+1 <<' ' <<y+1 <<a[k] <<endl;
        if(a[k]==s[0]){
            cout <<x+1 <<' ' <<y+1;
            return 0;
        }
        if(y==m-1&&!flag){
            flag =1 ;
            x++;
            continue;
        }else if(y==0 && flag){
            flag = 0;
        }
        if(flag){
            y--;
        }else {
            y++;
        }
    }
    return 0;
}

