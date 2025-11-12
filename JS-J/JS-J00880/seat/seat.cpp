#include<bits/stdc++.h>
using namespace std;
struct stu{
       int a;
       int xu;
}s[110];
bool cmp(stu x,stu y){
     return x.a>y.a;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int cn=n*m;
    for(int i=1;i<=cn;i++){
        cin>>s[i].a;
        s[i].xu=i;
    }
    sort(s+1,s+cn+1,cmp);
    int x=0,y=1;
    for(int i=1;i<=cn;i++){
        if(y%2==1){
           x++;
           if(x>n){y++;x--;}
        }else{
              x--;
              if(x<1){y++;x++;}
        }
        if(s[i].xu==1)break;
    }
    cout<<y<<" "<<x<<endl;
    return 0;
}
