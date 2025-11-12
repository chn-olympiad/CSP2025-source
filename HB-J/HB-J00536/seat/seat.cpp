#include<bits/stdc++.h>
using namespace std;
struct stu{
    int data;
    bool isr;
}a[105],b[15][15];
int n,m,x,y,g=1;
bool cmp(stu xxx,stu yyy){
    return xxx.data>yyy.data;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    x=1;y=1;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].data;
        if(i==1) a[i].isr=1;
    }
    sort(a+1,a+n*m+1,cmp);
    // for(int i=1;i<=n*m;i++){
    //     cout<<a[i].data<<" "<<a[i].isr<<endl;
    // }
    for(int i=1;i<=n*m;i++){
        // cout<<i<<"  "<<x<<" "<<y<<endl;
        b[x][y]=a[i];
        if(b[x][y].isr==1){
            cout<<y<<" "<<x<<endl;
            return 0;
        }
        if(g==-1&&x==1){
            g=1;y++;
        }
        else if(g==1&&x==n){
            g=-1;y++;
        }
        else{
            x+=g;
        }
    }
}