#include<bits/stdc++.h>
using namespace std;

int a[1000091],k=1;
int s[109][109];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];

    }
    int num=a[1];
    sort(a+1,a+n*m+1);
    k=n*m;

        for(int i=1;i<=n;i++){
            if(i%2!=0){
                for(int j=1;j<=m;j++){
                    s[i][j]=a[k];
                    k--;
                }


            }else{
                for(int j=m;j>=1;j--){
                    s[i][j]=a[k];
                    k--;
                }

            }




        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[j][i]==num){
                    cout<<j<<' '<<i;
                }

            }


        }

        return 0;
    }







