#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][100010],b[100010],sum;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n%2!=0){
            break;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(a[i][j]>a[i][j+1]){
                    b[i]=a[i][j];
                }
            }
        }
        for(int i=1;i<=n;i++){
            sum+=b[i];
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
