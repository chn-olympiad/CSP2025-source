#include<bits/stdc++.h>
using namespace std;
struct stu{
    int x,y,a,b;
};
int m,n;
int b;
bool cmp(stu x,stu y){
    return x.y>y.y;
}
int main(){
    stu s[1000];
    //3 3 94 95 96 97 98 99 100 92 93
    //#Shang4Shan3Ruo6Shui4
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int f=0,b1;
    for(int i=1;i<=m*n;i++){
        cin>>b;
        if(f==0) b1=b;
        f=1;
        s[i].y=b;
    }
    sort(s+1,s+m*n+1,cmp);
    for(int i=1;i<=m*n;i++){
        s[i].x=i;
    }
    int f1=0;
    for(int i=1;i<=m*n;i++){
        int t=0;
        s[1].b=1;
        s[1].a=1;
        if(i%n==1&&i!=1){
            s[i].a=s[i-1].a;
            s[i].b=t+i/n+1;
            t++;
            if(f1==0) f1=1;
            else f1=0;
        }else{
            if(i!=1){
                if(f1==0){
                s[i].a=s[i-1].a+1;
                s[i].b=s[i-1].b;
                }
                if(f1==1){
                s[i].a=s[i-1].a-1;
                s[i].b=s[i-1].b;
                }
            }
        }
        if(s[i].y==b1){
            cout<<s[i].b<<" "<<s[i].a;
            return 0;
        }
    }
    return 0;
}
