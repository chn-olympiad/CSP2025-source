#include<bits/stdc++.h>
using namespace std;
int s[110];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m*n;i++){
        cin>>s[i];
    }
    int xm=s[1];int q=0;
    sort(s+1,s+m*n+1,cmp);

    for(int i=1;i<=n*m;i++){cout<<s[i]<<' ';}
    cout<<endl;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                    q++;
                if(s[q]==xm){
                    cout<<i<<' '<<j;
                    break;
                }
            }
        }
        else if(i%2==0){
            for(int j=n;j>=1;j--){
                    q++;
                if(s[q]==xm){
                    cout<<i<<' '<<j;
                    break;
                }
            }
        }
    }
    return 0;
}
