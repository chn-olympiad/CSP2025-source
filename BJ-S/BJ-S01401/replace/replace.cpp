#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,wow1,wow2;
string temp1,temp2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>temp1>>temp2;
    }
    for(ll i=1;i<=q;i++){
        cin>>temp1>>temp2;
        ll len1=temp1.length();ll len2=temp2.length();
        if(len1!=len2){
            cout<<"0"<<endl;
            continue;
        }else{
            for(ll j=0;j<len1;j++){
                if(temp1[j]=='b'){
                    wow1=j;
                    break;
                }
            }
            for(ll j=0;j<len2;j++){
                if(temp2[j]=='b'){
                    wow2=j;
                    break;
                }
            }
            if(wow1!=wow2){
                cout<<"0"<<endl;
                continue;
            }else{
                cout<<n<<endl;
                continue;
            }
        }
    }
    return 0;
}

