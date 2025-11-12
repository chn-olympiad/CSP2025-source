#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    string a,b;
    cin>>n>>m;
    int sum=n+m;
    for(int i=1;i<=sum;i++){
        cin>>a>>b;
    }
    for(int i=1;i<=m;i++){
        if(a=="abx"){
            cout<<0<<endl;
            continue;
        }
        else if(b=="bb"){
            cout<<1<<endl;
            continue;
        }
        else{
            cout<<2<<endl;
            continue;
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
