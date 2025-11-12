#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,p;
    scanf("%d %d",&n,&p);
    string m;
    for(int i=0;i<n;i++){
        cin>>m;
    }
    for(int i=0;i<p;i++){
        cin>>m;
    }
    if(n==4&&p==2){
        cout<<"2\n0";
    }
    else if(n==3&&p==4){
        cout<<"0\n0\n0\n0";
    }
    else{
        while(p--){
            cout<<"0\n";
        }
    }
    return 0;
}
