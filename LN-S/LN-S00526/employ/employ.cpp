#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(m==1){
        cout<<n<<endl;
        return 0;
    }
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='1')a++;
        else b++;
    }
    cout<<(n*n/2*m-a*b)%998244353;
    return 0;
}
