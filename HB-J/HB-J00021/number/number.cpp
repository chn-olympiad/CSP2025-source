#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int j;
int num[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48&&s[i]<=57){
            num[j]=s[i]-'0';
            j++;
        }
    }
    sort(num,num+j);
    for(int i=j-1;i>=0;i--){
        cout<<num[i];
    }
    return 0;
}