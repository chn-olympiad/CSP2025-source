#include<bits/stdc++.h>
using namespace std;
int n,m,c[501];
string s;
bool flag;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            flag=true;
        }
    }
    if(!flag){
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
