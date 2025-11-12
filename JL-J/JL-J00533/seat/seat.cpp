#include<bits/stdc++.h>
using namespace std;
int m,n,c,t,r;
struct stu{
    int cj;
    int bh;
    int pm;
}a[110];
int b[11][11];
bool p(stu &a,stu &b){
    return a.cj>b.cj;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m*n;i++){
        cin>>a[i].cj;
        a[i].bh=i;
    }

    sort(a+1,a+m*n+1,p);
    for(int i=1;i<=m;i++){
        a[i].pm=i;
        if(a[i].bh==1){
            c=a[i].pm;
            break;
        }

    }
    if(c==1)
        cout<<1<<' '<<1;
    else if(c%(n*m)==0)
        cout<<m<<' '<<n;


    return 0;
}
