#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz=200050;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b[sz];
    cin>>n>>m;
    int a[100][100];
    int sum=n*m;
    if(sum==1){
        int dl;
        cin>>dl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    int y;
    for(int i=1;i<=sum;i++){
        cin>>b[i];
        if(i==1){
            y=b[i];
        }
    }
    int qq;
    for(int i=1;i<=sum;i++){
        for(int j=sum;j>=i;j--){
            if(b[j]>=b[j+1]){
                qq=b[j];
                b[j]=b[j+1];
                b[j+1]=qq;
            }
        }
    }
    int Xr=b[1];
    int jiedian=1;
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            for(int j=1;j<=m;j++){
                for(int k=jiedian;k<=sum;k++){
                    a[i][j]=b[k];
                    jiedian=k;
                }
            }
        }

        else{
            for(int j=m;j>=1;j--){
                for(int k=jiedian;k<=sum;k++){
                    a[i][j]=b[k];
                    jiedian=k;
                }
            }

        }
    }
    int w;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=m;j++){
            if(a[i][j]==y){
                cout<<i<<" ";
                break;
            }
        }
    }
    return 0;
}
//By Mr.Han
