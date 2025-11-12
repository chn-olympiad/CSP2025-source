#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;

int a[105];
int now,pos;

void dfs(int x,int y,int po){
    if(po==pos){
        cout << y << " " << x;
        exit(0);
    }
    if(y%2){
        if(x==n)dfs(x,y+1,po+1);
        else dfs(x+1,y,po+1);
    }else{
        if(x==1)dfs(x,y+1,po+1);
        else dfs(x-1,y,po+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> a[i];
    }
    now=a[1];
    sort(a+1,a+1+n*m);
    pos=lower_bound(a+1,a+1+n*m,now)-a;
    pos=n*m-pos+1;
    dfs(1,1,1);


    return 0;
}
