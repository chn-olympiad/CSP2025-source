#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N];
string s2[N];
string s3,s4;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++){
        cin>>s3>>s4;
    }
    int b3,b4;
    for(int i=1;i<=s3.size();i++){
        if(s3[i]=='b') b3=i;
    }
    for(int i=1;i<=s4.size();i++){
        if(s4[i]=='b') b4=i;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(s1[i].size()<abs(b3-b4)+1) continue;
        int b1,b2;
        for(int j=1;j<=s1[i].size();j++){
            if(s1[i][j]=='b') b1=i;
        }
        for(int j=1;j<=s2[i].size();j++){
            if(s2[i][j]=='b') b2=i;
        }
        if(b3<b4){
            if((s1[i].size()-b1)>=(abs(b3-b4)+1)&&(s1[i].size()-b1)<=(s3.size()-b3)&&(b2+1)>=(abs(b3-b4)+1)&&(b2+1)<=(b4+1)) cnt++;
        }
        if(b3>b4){
            if((s2[i].size()-b2)>=(abs(b3-b4)+1)&&(s2[i].size()-b2)<=(s4.size()-b4)&&(b1+1)>=(abs(b3-b4)+1)&&(b1+1)<=(b3+1)) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
