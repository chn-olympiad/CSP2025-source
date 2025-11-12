#include<bits/stdc++.h>
using namespace std;
string s;
int cnt=1;
const int N=1000;
char num[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    int k;
    for(int i=0;i<s.size();i++){
        k=(int)s[i];
        if(k>=48&&k<=57){
            num[cnt]=s[i];
            cnt++;
        }
    }
    cnt--;
    sort(num,num+cnt+1);
    for(int i=cnt;i>=1;i--){
            cout<<num[i];
    }
   return 0;
}
