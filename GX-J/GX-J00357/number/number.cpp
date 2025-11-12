#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
string s1;
long long a[N],sum = 0;
stack<int > s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s1;
    for(int i = 0;i<s1.size();i++){
        if(s1[i]>='0'&&s1[i]<='9'){
            int b = s1[i]-'0';
            a[b]++;
        }
    }
    for(int i = 9;i>=0;i--){
        for(int j = 1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
