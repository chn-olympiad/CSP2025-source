#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[5000][5000],s;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans[i][j]=ans[i][j-1]^a[j];
        }
    }
    int f=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(ans[i][j]==m){
                s++;
                if(j!=n)
                    i=j+1;
                else{
                    f=0;
                    break;
                }
            }
        }
        if(!f)
            break;
    }
    cout<<s;
}
