#include<bits/stdc++.h>
using namespace std;
int n,m,seat,line,_seat;
struct Stu{
    int score,id;
}a[200];
bool cmp(Stu s1,Stu s2){
    return s1.score>s2.score;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i].score;
        a[i].id=i;
    }
    sort(a+1,a+m*n+1,cmp);
    for(int i=1;i<=m*n;i++){
        if(a[i].id==1){
            seat=i;
            break;
        }
    }
    if(seat%n==0) _seat=seat/n;
    else _seat=seat/n+1;
    if(_seat%2==1){
        line=seat%n;
        if(line==0) line=n;
    }
    else{
        line=n-seat%n+1;
        if(line==n+1) line=1;
    }
    cout<<_seat<<" "<<line;
    return 0;
}
