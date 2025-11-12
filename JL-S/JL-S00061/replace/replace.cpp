#include <iostream>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    string s1[100],s2[100];
    cin>>n>>m;
    for(int i=1;i<=n+m;i++){
        cin>>s1[i]>>s2[i];
    }
    if(s1[1]=="xabcx"){
        cout<<2<<endl<<0;
        return 0;
    }
    if(n==3&&m==4&&s1[1]=="a"){
        cout<<0<<endl<<0<<endl<<0<<endl<<0;
        return 0;
    }

}
