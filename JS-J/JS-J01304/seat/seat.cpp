#include <bits/stdc++.h>
using namespace std;
pair<int,int> stu[1000];
bool cmp(pair<int,int> stu1,pair<int,int> stu2){
    return stu1.first>stu2.first;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>stu[i].first;
        stu[i].second=i;
    }
    sort(stu+1,stu+n*m+1,cmp);
    int x=1,y=1,dx=1,dy=0;
    for(int i=1;i<=n*m;i++,x+=dx,y+=dy){
        if(stu[i].second==1){
            cout<<y<<' '<<x<<endl;
            return 0;
        }
        if(x==n&&dx==1){
            dx=0;
            dy=1;
            continue;
        }
        if(x==1&&dx==-1){
            dx=0;
            dy=1;
            continue;
        }
        if(x==n&&dy==1){
            dx=-1;
            dy=0;
            continue;
        }
        if(x==1&&dy==1){
            dx=1;
            dy=0;
            continue;
        }
    }
    return 0;
}
