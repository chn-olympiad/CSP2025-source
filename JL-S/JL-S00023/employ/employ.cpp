#include<bits/stdc++.h>
using namespace std;
int n,m,fc=0;
string s;
const int c[n];
int main(){
    freopen("employ.cpp","r",stdin);
    freopen("employ.cpp","w",stdout);
    cin>>n>>m>>s>>c[n];
    for(int i;i<=n;i++){
        if(c[i]==0)
            fc+=1;

    }
    for(int j;j<=n;i++){
        if(fc>=c[i]&&c[i]!=0)
            fc+=1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
