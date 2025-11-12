#include<bits/stdc++.h>
using namespace std;

int t,n,s=0;
int a[100001][4];
int b[100001];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t){
        t--;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][j]==0){
                    s++;
                }
            }
        }
        if(s>=2*n){
           for(int i=1;i<=n;i++){
                b[i]=a[i][1];
            }
            sort(b+1,b+1+n);
            cout<<b[n]+b[n-1]<<endl;
        }
        else if(s>=n&&s<2*n){
            for(int i=1;i<=2;i++){
                for(int i=1;i<=n;i++){
                    b[i]=a[i][1];
                }

            }
        }
    }
    return 0;
}
