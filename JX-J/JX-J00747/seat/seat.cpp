#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000+10;
int n,m,b[N][N];
struct stu{
    int a;
}t[N];
bool cmp(stu x,stu y){
    return x.a>y.a;
}
int main(){
    freopen("seat.in","r",stdin);//please open it
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int s=n*m;
    for(int i=1;i<=s;i++){
        cin>>t[i].a;
    }
    int ta=t[1].a;
    sort(t+1,t+s+1,cmp);
    for(int i=1;i<=n;i++){
        int ii=i;
        if(ii%2){
            for(int j=1;j<=m;j++){
                b[i][j]=t[(i-1)*m+j].a;
            }
        }else{
            for(int j=m;j>=1;j--){
                b[i][j]=t[(i-1)*m+m-j+1].a;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==ta){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
