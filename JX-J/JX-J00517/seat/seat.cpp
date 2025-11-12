#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    if(a>=b) return true;
    return false;
}
int a[12][12];
int b[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n/*hang*/,m/*lie*/;
    cin>>n>>m;
    if(n==1&&m==1){
        cout<<1<<" "<<1;
        return 0;
    }

    int findR/*zhui zong xiaoR*/;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
        if(i==1)
        findR=b[i];
    }
    sort(b+1,b+n*m+1,cmp);
    int sf=0;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                sf++;
                a[i][j]=b[sf];
            }
        }
        else{
            for(int j=m;j>=1;j--){
                sf++;
                a[i][j]=b[sf];
            }
        }
    }
    for(int i=1;i<=m;i++){
        bool getfind=false;
        for(int j=1;j<=n;j++){
            if(a[j][i]==findR){
                cout<<j<<" "<<i;
                getfind=true;
                break;
            }
        }
        if(getfind==true)
        break;
    }
    return 0;
}


