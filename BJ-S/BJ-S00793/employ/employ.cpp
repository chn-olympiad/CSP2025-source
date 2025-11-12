#include<bits/stdc++.h>
using namespace std;
long long int c[9999999];
long long int k[9999999];
int slow;
int shig;
int ansp=0;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++){
        if(s[i]=='0') shig++;
        if(s[i]=='1') slow++;
    }
    if(m<shig){
        cout<<"0"<<endl;
        return 0;
    }
    sort(c,c+n);
    for(int i=0;i<n;i++){
        if(c[i]!=0){
            ansp+=c[i];
        }
    }cout<<ansp-1;
    return 0;
}
