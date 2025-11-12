#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,c,r;
struct seat{
    int student,score;
}a[105];
bool cmp(seat p,seat q){
    return p.score>q.score;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i].score,a[i].student=i;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].student==1){
            c=(i+n-1)/n;
            if(c%2) r=i-(c-1)*n;
            else r=c*n-i+1;
            break;
        }
    }
    cout<<c<<" "<<r<<" \n";
    return 0;
}
