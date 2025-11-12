#include<bits/stdc++.h>
using namespace std;
const int N=1010;
string s;
int tong[9];
int num[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    if(s.size()==1){
        cout<<s;
    }
    if(s.size()>1){
        for(int i=0;s[i];i++){
            if(s[i]=0||1||2||3||4||5||6||7||8||9){
                tong[s[i]]++;
                num[s[i]]=s[i];
            }
        }
        for(int i=9;i>=0;i--){
            if(tong[i]>0){
                cout<<num[i];
                tong[i]--;
            }
        }
    }
    return 0;
}
