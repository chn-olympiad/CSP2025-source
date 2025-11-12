#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    long long bj[100001]={},s=0,l=0;
    cin>>n;
    for(int i=0;i<n.size();i++){
        if(n[i]>='0' and n[i]<='9'){
            bj[i]=n[i]-'0';
            s++;
        }
        else{
                bj[i]=11;
        }
    }
    sort(bj,bj+n.size()+1);
    for(int i=s;i>=1;i--){
            if(bj[i]==11){
                l=1;
            }
            else{
                cout<<bj[i];
            }
    }
    return 0;
}
