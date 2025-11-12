#include<bits/stdc++.h>
using namespace std;
int a[110][110];
int b[10010];
int main(){
   freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,ans_n,ans_m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    r=b[1];
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }*/
    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(b[i]<b[j]){
                int temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }

        }
    }
    int t;
    for(int i=1;i<=n*m;i++){
        if(r==b[i]){
            if(i%n!=0){
                ans_n=i/n+1;
            }
            else{
                ans_n=i/n;
            }
            t=i-(ans_n-1)*n;
            if(ans_n%2==0){
                    ans_m=n-t+1;
                cout<<ans_n<<" "<<ans_m;
            }
            else{
                ans_m=t;
                cout<<ans_n<<" "<<ans_m;
            }
        }
    }
    /*for(int i=1;i<=n*m;i++){
        cout<<b[i]<<" ";
    }*/
    return 0;
    }
