#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int num[N], tmp;
string s;
bool cmp(int x, int y){
     return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[tmp++]=s[i]-'0';
        }
    }
    sort(num, num+tmp, cmp);
    for(int i=0; i<tmp; i++){
        cout<<num[i];
    }
    return 0;
}
