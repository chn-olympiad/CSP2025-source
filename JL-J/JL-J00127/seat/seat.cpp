#include<bits/stdc++.h>
using namespace std;
struct stu{
    int cj,bh,id,r,c;
}a[105];
bool cmp(stu a,stu b){
    return a.cj>b.cj;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int p=n*m;
    for(int i=1;i<=p;i++){
        cin>>a[i].cj;
        a[i].id=i;
    }
    sort(a+1,a+p+1,cmp);
    for(int i=1;i<=p;i++){
        a[i].bh=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(i%2){
                a[m*(i-1)+j].c=i;
                a[m*(i-1)+j].r=j;
            }
            else{
                a[m*(i-1)+j].c=i;
                a[m*(i-1)+j].r=n-j+1;
            }
        }
    }
    for(int i=1;i<=p;i++){
        if(a[i].id==1){
            cout<<a[i].c<<" "<<a[i].r;
        }
    }

    return 0;
}
