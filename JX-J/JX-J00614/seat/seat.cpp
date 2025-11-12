#include<bits/stdc++.h>
using namespace std;
int s[15][15];
int a[105];
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    int sc=a[1];
    sort(a+1,a+n*m+1);
    //for(int i=1;i<=n*m;i++){
    //    cout<<a[i]<<' ';
    //}
    int idx=n*m;
    for(int i=1;i<=m/2;i++){
        for(int j=1;j<=n;j++){
            s[i][j]=a[idx];
            if(a[idx]==sc){
                cout<<i<<' '<<j<<'\n';
                return 0;
            }
            idx--;
            //cout<<"AAA"<<i<<' '<<j<<endl;
        }
        for(int j=n;j>=1;j--){
            s[i*2][j]=a[idx];
            if(a[idx]==sc){
                cout<<i*2<<' '<<j<<'\n';
                return 0;
            }
            idx--;
            //cout<<"BBB"<<i*2<<' '<<j<<endl;
        }
    }
    if(n&1){
        for(int j=1;j<=n;j++){
            s[n][j]=a[idx];
            if(a[idx]==sc){
                cout<<n<<' '<<j<<'\n';
                return 0;
            }
            idx--;

            //cout<<"CCC"<<n<<' '<<j<<endl;
        }
    }
    cout<<m<<' '<<n<<'\n';
    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=m;j++){
    //        cout<<s[i][j]<<' ';
    //    }
    //    cout<<'\n';
    //}
    return 0;
}
