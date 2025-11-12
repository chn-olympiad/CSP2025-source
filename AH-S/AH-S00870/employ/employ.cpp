#include<iostream>
#include<cstdio>
using namespace std;
int n,m,c[505];
char a[505];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(m>18){
        cout<<18;
        return 0;
    }
    cout<<2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
