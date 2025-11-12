#include<bits/stdc++.h>
using namespace std;
int n,m,f,cur;
struct node{
    int score;
    bool flag;
}stu[105];
bool cmp(node a,node b){
    return a.score>b.score;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    f=n*m;
    for(int i=1;i<=f;i++){
        cin>>stu[i].score;
        if(i==1) stu[i].flag=true;
        else stu[i].flag=false;
    }
    stable_sort(stu+1,stu+f+1,cmp);
    for(int i=1;i<=m;i++){
        int x=-1,y=-1;
        if(i%2==1){
            for(int j=1;j<=n;j++){
                cur++;
                if(stu[cur].flag){
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                cur++;
                if(stu[cur].flag){
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        if(x!=-1&&y!=-1){
            cout<<x<<" "<<y;
            return 0;
        }
    }
    return 0;
}
//Hope to have a good ending.