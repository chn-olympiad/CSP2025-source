#include <bits/stdc++.h>
using namespace std;
int n, m, s, num, x, y;
int sc[1000];

bool cmp(int x, int y){
    return x > y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","r",stdout);
    cin >> n >> m >> s;
    sc[1] = s;
    for(int i = 2; i <= n*m; i++)
        cin >> sc[i];

    sort(sc+1, sc+1+n*m, cmp);
    for(int i = 1; i <= n*m; i++){
        if(sc[i]==s){
            num = i;
            break;
        }
    }

    x = num/m;
    if(num%m)  x+=1;
    y = num%m;
    if(y==0 && x%2==0) y=1;
    else if(y==0 && x%2) y=n;
    else if(y&&x%2==0) y = n-y+1;

    cout << x <<" "<< y;

    return 0;
}
