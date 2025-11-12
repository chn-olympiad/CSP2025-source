#include<bits/stdc++.h>
using namespace std;
int n,ans;
const int N=1e6+5;
string s;
int m[N];
int a;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    if(s.size()==1) cout<<s<<endl;
    else{
        for(int i=0;i<=s.size()+1;i++){
            s[i]/10;
            if(s[i]>s[i+1]){
                cout<<s[i]<<endl;
            }
        }
    }
    return 0;
}
