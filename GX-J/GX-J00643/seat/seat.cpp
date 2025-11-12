#include<bits/stdc++.h>
using namespace std;
int n,m,a[103],cnt=0,t;
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    t=a[0];
    sort(a,a+n*m,cmp);
    for(int i=1;i<=m;i++){
        if(!(i%2)){
            for(int j=1;j<=n;j++){
                if(a[cnt]==t){
                    cout<<j<<' '<<i;
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
                cnt++;
            }
        }else{
            for(int j=n;j>0;j--){
                if(a[cnt]==t){
                    cout<<j<<' '<<i;
                    fclose(stdin);
                    fclose(stdout);
                    return 0;
                }
                cnt++;
            }
        }
    }
}
