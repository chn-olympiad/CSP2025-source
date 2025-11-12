#include<bits/stdc++.h>
using namespace std;
int a[15][15];
struct stu{
    int mar;
    int num;
}s[105];
bool cmp(stu a,stu b){
    return a.mar>b.mar;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i].mar;
        s[i].num=i;
    }
    sort(s+1,s+1+n*m,cmp);
    for(int i=1;i<=n;i++){
        if(i%2==1){
            a[i][1]=a[i-1][1]+1;
            for(int j=2;j<=m;j++){
                a[i][j]=a[i][j-1]+1;
            }
        }else{
            a[i][m]=a[i-1][m]+1;
            for(int j=m-1;j>=1;j--){
                a[i][j]=a[i][j+1]+1;
            }
        }
    }
    int pos;
    for(int i=1;i<=n*m;i++){
        if(s[i].num==1){
            pos=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==pos){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }

	return 0;
}
