#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a1,s[15][15],a;
    cin>>n>>m;
    cin>>a1;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                cin>>s[i][j];
                if(s[i][j]<a1&&i==1&&j==1)
                    j++;
                if(i==1){
                    if(s[i][j]<a1){
                        cout<<i<<' '<<j;
                        return 0;
                    }
                }
                if(j==1){
                    if(s[i][j]<a1&&s[i][j]<s[i-1][1]){
                        cout<<i<<' '<<j;
                        return 0;
                    }
                }
                if(j!=1){
                    if(s[i][j]<a1&&s[i][j]<s[i][j-1]){
                        cout<<i<<' '<<j;
                        return 0;
                    }
                }
            }
        }else{
            for(int j=m;j>0;j--){
                cin>>s[i][j];
                if(j==m){
                    if(s[i][j]<a1&&s[i][j]<s[i-1][m]){
                        cout<<i<<' '<<j;
                        return 0;
                    }
                }
                if(j!=m){
                    if(s[i][j]<a1&&s[i][j]<s[i][j+1]){
                        cout<<i<<' '<<j;
                        return 0;
                    }
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
return 0;
}
