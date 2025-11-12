#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')cnt++;
    }
    if(cnt<m){
        cout<<0;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(m==n){
        sort(a+1,a+n+1);
        for(int i=0;i<n;i++){
            if(s[i]=='0'||(a[i]!=n-1&&a[i]==a[i-1])){
                cout<<0;
                fclose(stdin);
                fclose(stdout);
                return 0;
            }

        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
