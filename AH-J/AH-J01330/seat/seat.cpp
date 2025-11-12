#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[205];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);//wenjian
    freopen("seat.out","w",stdout);//wenjian
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int y=a[1];
    int p;
    int o=n*m;
    sort(a+1,a+o+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==y){
            p=i;
        }
    }
    //cout<<p<<" ";
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                p--;
                if(p==0){
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
        } else {
            for(int i=n;i>=1;i--){
                p--;
                if(p==0){
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
        }
    }
    fclose(stdin);//IOADHNIOWHADI
    fclose(stdout);//asdihjedf
    return 0;
}
