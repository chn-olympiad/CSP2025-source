#include<bits/stdc++.h>
using namespace std;
int main(){
     int n,m,k;
     int c[100005],p[100005];
     string s;
     cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        cin >> s[m] >> c[i];
    }
    for(int i=1;i<=n;i++){
        if(s[i]=0){
            c[i]++;
        }
        else{
            m++;
        }
        if(k>=c[i]){
            n--;
        }
    cout <<p[m];
    }
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    return 0;
}
