#include <bits/stdc++.h>
using namespace std;
//seat

int n,m,c,row,col,idx;
int a[107];

bool mycmp(int a,int b){
    return a > b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n * m;i++){
        scanf("%d",&a[i]);
    }
    c = a[1];
    sort(a + 1,a + 1 + n * m,mycmp);
    for (int i = 1;i <= n * m;i++){
        if (a[i] == c){
            idx = i;
            break;
        }
    }
    //printf("%d %d ll\n",idx,a[1]);
    col = idx / n;
    if (idx % n)col++;
    if (col & 1){
        row = (idx - 1) % n + 1;
    }
    else{
        row = n - (idx - 1) % n;
    }
    printf("%d %d\n",col,row);
    return 0;
}
