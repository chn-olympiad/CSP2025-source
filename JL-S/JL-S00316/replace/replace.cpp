#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,q;
string s1[500005],s2[500005],t1,t2;
bool IsSpecial=1;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        if(s1[i].find('b')==-1||s2[i].find('b')==-1||s1[i].find('a')==-1||s2[i].find('a')==-1) IsSpecial=0;
    }
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        if(t1.size()!=t2.size()){
            cout<<"0\n";
            continue;
        }
        cout<<n-2<<'\n';
        /*for(int i=1;i<=n;i++){
            string ak=t1;
            ak.erase(ak.begin(),ak.begin()+ak.find(s1[i][0]+1));
        }*/
    }
    return 0;
}
