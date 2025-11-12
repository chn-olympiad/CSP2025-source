#include<bits/stdc++.h>
using namespace std;
int n,m;
struct stu{
    int s,p;
}a[105];
bool cmp(stu x,stu y){
    return x.s>y.s;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].s;
        a[i].p=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                cnt++;
                if(a[cnt].p==1){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                cnt++;
                if(a[cnt].p==1){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
