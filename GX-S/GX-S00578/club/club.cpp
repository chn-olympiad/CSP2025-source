#include <bits/stdc++.h>
using namespace std;



int main(){
    //freopen("club.in","r",stdin);

    //freopen("club.out","w",stdout);

    //ios::sync_with_stdio(false);

    int t,n,a1,a2,a3,ans;
    int b[10010] ={0};
    cin >>t>>n;
    whlie (t!=0){
    for (int i=1;i<3;i++){
        cin>>a1>>a2>>a3;

        for (int j=1;j<=n;j++){
             if (a1>a2&&a1>a3){

                b[j]=a1;
             }
             if (a2>a1&&a2>a3){
				 b[j]=a2;
             }
             if (a3>a1&&a3>a2){
                b[j]=a3;
             }
             a1=a2=a3=0;
             --t;
             }
        }
    }
    for (int i=1;i<=n;i++){
        ans += b[i];
    }
    cout << ans;

    }
