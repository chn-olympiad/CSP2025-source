#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
bool cmp(int x,int y){
    return x>y;
}
int a[105],cnt,pos;//1 ≤ n ≤ 10,1 ≤ m ≤ 10;
//为小 R CSP-J 2025 第一轮的成绩,
//他的座位为第几列第几行
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[++cnt];
            //cout<<a[cnt]<<" ";
        }
    }
    pos=a[1];
    sort(a+1,a+cnt+1,cmp);
    int x=1,y=1,z=1;
    for(int i=1;i>0;i++){

        //cout<<a[i]<<" ";
        if(a[i]==pos){
            cout<<y<<" "<<x;
            return 0;
        }
        if(z==1){
            if(x==n){
                y++;
                z=0;
            }else{
                x++;
            }
        }else{
            if(x==1){
                y++;
                z=1;
            }else{
                x--;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
