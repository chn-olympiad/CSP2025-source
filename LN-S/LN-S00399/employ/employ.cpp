#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,ans = 0,tmp = 0;
    cin>>n>>m;
    string c;
    cin>>c;
    int b[n+1];
    for (int i = 1;i<n;i++){
        cin>>b[i];
    }
    for(int i = 0;i<n;i++){
        if (b[i] == 0){
            tmp++;
            ans++;
        }
    }
    for(int i = 1;i<=n;i++){
        if(b[i] >= tmp){
            tmp--;
        }
        if (tmp == 0){
            cout<<n - ans;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
            }


