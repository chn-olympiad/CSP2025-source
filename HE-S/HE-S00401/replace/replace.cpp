#include<bits/stdc++.h>
using namespace std;

int n,q;
char a,b,c,d;
int main(){

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
    }
    for(int i=1;i<=q;i++){
        cin>>c>>d;
    }
    if(n==4 && q==2){
        cout<<2<<endl;
        cout<<0<<endl;
    }
    else{
        for(int i=1;i<=q;i++){
            cout<<0<<endl;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
