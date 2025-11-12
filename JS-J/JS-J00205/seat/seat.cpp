#include<bits/stdc++.h>
using namespace std;
struct stu{
    int mark,id;
}a[101];
bool cmp(stu x,stu y){
    return x.mark>y.mark;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i].mark;
        a[i].id=i;
    }
    sort(a+1,a+1+n*m,cmp);
    int s=0;
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            s=i;
            break;
        }
    }
    if(s%n==0){
        if((s/n)%2==0)cout<<s/n<<' '<<1;
        else cout<<s/n<<' '<<n;
    }else{
        if((s/n)%2==0)cout<<s/n+1<<' '<<s%n;
        else cout<<s/n+1<<' '<<n-(s%n)+1;
    }
    return 0;
}
