#include<bits/stdc++.h>
using namespace std;
struct students{
    int score;
    int n;
}a[105];
students ans[15][15];
bool cmp(students x,students y){
    return x.score>y.score;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int b;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>b;
            a[(i-1)*n+j].score=b;
            a[(i-1)*n+j].n=(i-1)*n+j;
        }
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            ans[j][i]=a[(i-1)*m+j];
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=1;j<=n/2;j++){
                swap(ans[j][i],ans[n-j+1][i]);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(ans[i][j].n==1)cout<<i<<' '<<j<<endl;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout<<ans[i][j].score<<' ';
        }
        cout<<endl;
    }
    return 0;
}
