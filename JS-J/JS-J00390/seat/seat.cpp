#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int id,score,x,y;//x shi hang,y shi lie
};
node a[105];
bool cmp(node a,node b){return a.score>b.score;}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n*m;i++){
        cin>>a[i].score;
        a[i].id=i;

    }
    int Rscore=a[1].score;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n*m;i++){
        a[i].y=ceil(1.0*i/n);
        if(a[i].y%2!=0){
            a[i].x=i-(a[i].y-1)*n;
        }
        else a[i].x=n-(i-(a[i].y-1)*n)+1;
    }
    //kai shi er fen zhao R
    int l=1,r=n*m;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid].score>=Rscore){
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    cout<<a[ans].y<<' '<<a[ans].x;//zhu yi! zhe li yao xian shu chu lie zai shu chu hang
    return 0;
}
