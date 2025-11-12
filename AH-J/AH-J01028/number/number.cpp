#include<bits/stdc++.h>
using namespace std;
string s,sum;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            sum+=s[i];
        }
    }
    sort(sum.begin(),sum.end());
    for(int i=sum.size()-1;i>=0;i--){
        cout<<sum[i];
    }
    return 0;
}
