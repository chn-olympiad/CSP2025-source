#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
    return x > y;
}
int a[110];
int main(){
    freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n * m;i++){
        scanf("%d",&a[i]);
    }
    int p = a[1];
    sort(a + 1,a + n * m + 1,cmp);
    int pos;
    for(int i = 1;i <= n * m;i++){
        if(a[i] == p){
            pos = i;
        }
    }
    int c = (pos + n - 1) / n;
    int r;
    if(c % 2 == 1){
        r = pos - n * (c - 1);
    }
    else{
        r = n - (pos - n * (c - 1)) + 1;
    }
    printf("%d %d\n",c,r);
    return 0;
}
