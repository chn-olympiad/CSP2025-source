#include<bits/stdc++.h>
using namespace std;
int a[100008][18];
int b[18];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin>>t;
    for(int q=1;q<=t;q++){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][j]>a[i][4]){
                    a[i][4]=a[i][j];
                    a[i][5]=j;
                }
                b[a[i][5]]++;
            }
        }
        int m=n/2;
        int f=1;
        for(int i=1;i<=3;i++){
            if(b[i]>m){
                f=0;
                break;
            }
        }
        int s=0;
        for(int k=1;k<=n;k++){
            s+=a[k][4];
        }
        cout<<s;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
