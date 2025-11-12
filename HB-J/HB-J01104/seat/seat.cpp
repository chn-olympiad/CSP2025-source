#include <bits/stdc++.h>
using namespace std;

const int N=20;
int n,m,f=1,x=1,y=1;//0 up,1 down,2 right

struct lyc{
    int grude;
    bool r;
}a[N*N];

bool cmp(lyc x,lyc y){
    return x.grude>y.grude;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int nm=n*m;
    for(int i=1;i<=nm;i++){
        cin>>a[i].grude;
        if(i==1) a[i].r=1;
    }
    sort(a+1,a+nm+1,cmp);
    int goal;
    for(int i=1;i<=nm;i++){
        if(a[i].r==1){
            goal=i;
            break;
        }
    }
    for(int i=2;i<=goal;i++){
        if(f==1&&y==n||f==0&&y==1) f=2;
        if(f==0) y--;
        else if(f==1){
            y++;
        }
        else if(f==2){
            x++;
            if(y==1) f=1;
            else if(y==n) f=0;
        }
    }
    cout<<x<<' '<<y;
    return 0;
}

