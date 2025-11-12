#include <bits/stdc++.h>
using namespace std;
struct stu{
    int id;
    int c;
};
stu a[105];
bool cmp(stu x,stu y){
    return x.c>y.c;
}
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> a[i].c;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            int ans,num;
            if(i%n==0){
                ans=i/n;
                num=n;
            }
            else{
                ans=i/n+1;
                num=i%m;
            }
            if(ans%2==1){
                cout << ans << " " << num;
            }
            else{
                cout << ans << " " << n-num+1;
            }
            break;
        }
    }
    return 0;
}
