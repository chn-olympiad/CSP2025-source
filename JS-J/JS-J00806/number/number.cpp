#include<bits/stdc++.h>
using namespace std;
string s;
int nu[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    int j=1;
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            nu[j]=int(s[i]-'0');
            j++;
        }
    }
    sort(nu+1,nu+j);
    for(int i=j-1;i>=1;i--){
        cout<<nu[i];
    }
    return 0;
}
