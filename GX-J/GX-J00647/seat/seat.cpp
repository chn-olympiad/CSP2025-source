#include<bits/stdc++.h>
using namespace std;
struct stu{
    int v,b;
};
bool cmp(stu a,stu b){
    return a.v>b.v;
}
int n,m,x=1,y=1;
stu a[110];
void dfs(){
    for(int i=1;i<=n*m;i++){
        if(i!=1){
            if(x%2!=0){
                if(y==n){
                    x++;
                }else{
                    y++;
                }
            }else{
                if(y==1){
                    x++;
                }else{
                    y--;
                }
            }
        }
        //cout<<x<<" "<<y<<endl;
        if(a[i].b==1) return;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].v;
        a[i].b = i;
    }
    int b = n*m;
    sort(a+1,a+1+b,cmp);
    dfs();
    cout<<x<<" "<<y;
    return 0;
}
