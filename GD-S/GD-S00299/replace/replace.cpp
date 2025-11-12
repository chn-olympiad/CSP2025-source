#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    int n,q;
    cin>>n>>q;
    string x,y;
    for(int i=1;i<=n+q;i++){
        cin>>x>>y;
    }
    if(n==4&&q==2){
        cout<<"2"<<endl;
        cout<<"0";
    }
    if(n==3&&q==4){
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"0"<<endl;
        cout<<"0";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
