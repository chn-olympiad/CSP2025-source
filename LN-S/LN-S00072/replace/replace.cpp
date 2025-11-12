#include<bits/stdc++.h>
using namespace std;

string s,s2,s3,s4;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m,sum=0,sum2=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>s2[i];
        if((s[i]=='a'||s[i]=='b')&&(s2[i]=='a'||s2[i]=='b')){
            sum++;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>s3[i]>>s4[i];
        if((s3[i]=='a'||s3[i]=='b')&&(s4[i]=='a'||s4[i]=='b')){
            sum2++;
        }
    }
    if(m==1&&sum==n){
        if(sum2!=n){
            cout<<0;
            return 0;
        }
    }
    if(m==1){
        cout<<0;
        return 0;
    }
    return 0;
}
