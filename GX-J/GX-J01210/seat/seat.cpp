#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}
long long zuo[20][20],n,m,ab[500],xiaoR,k=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    cin>>xiaoR;
    for(int i=1;i<=n*m-1;i++){
        cin>>ab[i];
    }
    ab[n*m]=xiaoR;
    sort(ab+1,ab+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                zuo[j][i]=ab[k];
                if(ab[k]==xiaoR){
                    cout<<n<<m;
                    return 0;
                }
                k++;
            }
        }
        if(i%2==0){
            for(int j=n;j>=1;j--){
                zuo[j][i]=ab[k];
                if(ab[k]==xiaoR){
                    cout<<n<<m;
                    return 0;
                }
                k++;
            }
        }
    }

    return 0;
}