#include<bits/stdc++.h>
using namespace std;
int n,m,k=0,l=0;
bool flag=false;
struct stu{
    int s,x,y;
}a[1005];
bool cmp(stu a,stu b){return a.s>b.s;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].s;
    }
    k=a[1].s;
    sort(a+1,a+n*m+1,cmp);
    for(int j=1;j<=m;j++){
        if(flag==false){
            for(int i=1;i<=n;i++){
                l++;
                a[l].x=i;a[l].y=j;
            }
        }else{
            for(int i=n;i>=1;i--){
                l++;
                a[l].x=i;a[l].y=j;
            }
        }
        flag=!flag;
    }
    for(int i=1;i<=l;i++){
        if(a[i].s==k){
            cout<<a[i].y<<" "<<a[i].x;
            return 0;
        }
    }
    return 0;
}
