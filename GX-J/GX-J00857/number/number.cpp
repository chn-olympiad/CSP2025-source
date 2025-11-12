#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string n;
    cin>>n;
    char m[100005];
    for(int i=0;i<=n.size();i++){
        if(n[i]>='0' && n[i]<='9'){
            m[i]=n[i];
        }
    }
    if(n.size()==1){
        cout<<n;
    }
    else{
        for(int i=0;i<=n.size();i++){
            for(int j=0;j<=n.size();j++){
                if(m[i]<m[j]){
                    char t[100];
                    t[0]=m[i];
                    m[i]=m[j];
                    m[j]=t[0];
                }
            }
        }
        for(int i=n.size();i>=0;i--){
            cout<<m[i];
        }
    }

    return 0;

}
