#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int s[101];
    int e[12][12];
    int a,n,m,t;
    cin >> n >> m;
    for(int i=0;i<n*m;i++){
        cin >> s[i];
    }
    a=s[0];
    for(int i=0;i<n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(s[i]<s[j]){
                t=s[i];
                s[i]=s[j];
                s[j]=t;
            }
        }
    }
    int j=1,cnt=0;
    for(int i=1;i<=m;i++){
        if(j<=1){
            for(j=1;j<=n;j++){
                e[i][j]=s[cnt];
                cnt++;
            }

        }
        else{
            for(j=n;j>=1;j--){
                e[i][j]=s[cnt];
                cnt++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(e[i][j]==a){
                cout << i << " " << j;
                break;
            }
        }
    }

    return 0;
}
