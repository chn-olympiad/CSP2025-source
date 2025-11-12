#include <bits/stdc++.h>
using namespace std;
struct exam{
    long long sc,id;
}a[210];
long long n,m,R,num,mp[20][20],numx=1;
bool cmp(exam x,exam y){
    return x.sc>y.sc;
}
priority_queue<int,vector<int> > q;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            mp[i][j]=numx++;
        }
    }
    for(int j=2;j<=m;j+=2){
        for(int i=1;i<=n;i++){
            q.push(mp[i][j]);
        }
        for(int i=1;i<=n;i++){
            mp[i][j]=q.top();
            q.pop();
        }
    }
    for(int i=1;i<=n*m;i++){
        scanf("%lld",&a[i].sc);
    }
    R=a[1].sc;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)a[i].id=i;
    for(int i=1;i<=n*m;i++){
        if(a[i].sc==R){
            num=a[i].id;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(num==mp[i][j]){
                printf("%d %d",j,i);
                return 0;
            }
        }
    }
    return  0;
}
