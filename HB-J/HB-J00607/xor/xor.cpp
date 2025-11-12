#include <bits/stdc++.h>
using namespace std;
int a[5000][5000],n,k,e=1,cnt=0,top=0x3f;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int q;
        cin>>q;
        for(int j=1;j<=i;j++){
            if(i==j){
                a[i][j]=q;
            }
            else{
                a[j][i]=a[j][i-1]^q;
            }

        }
    }
    for(int i=1;i<=n;i++){//1~n
        top=0x3f;
        for(int j=i;j<=n;j++){//i~n
            if(a[i][j]==k&&i>e){
                top=min(top,j);
            }
        }
        if(top!=0x3f){
            cnt++;
            e=top;
        }
    }
    cout<<cnt;
    return 0;
}
