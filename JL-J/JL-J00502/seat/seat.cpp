#include<bits/stdc++.h>
using namespace std;
struct student{
    long long score;
    bool f=false;
};
student a[105];
bool cmp(student a,student b){
    return a.score>b.score;
}
long long s[15][15];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,k=1;
    bool f=true;
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
        cin>>a[i].score;
    }
    a[1].f=true;
    sort(a+1,a+(n*m)+1,cmp);
    for(long long i=1;i<=m;i++){
        if(f==true){
            for(long long j=1;j<=n;j++){
                if(a[k].f==true){
                    cout<<i<<' '<<j<<endl;
                    return 0;
                }
                s[j][i]=a[k].score;
                k++;
                f=false;
            }
        }
        else{
            for(long long j=n;j>0;j--){
                if(a[k].f==true){
                    cout<<i<<' '<<j<<endl;
                    return 0;
                }
                s[j][i]=a[k].score;
                k++;
                f=true;
            }
        }
    }
    return 0;
}
