#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string str;
char str1[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    int ss=str.size();
    int j=0;
    for(int i=0;i<ss;i++){
        if(str[i]>='0' && str[i]<='9')
            str1[j++]=str[i];
    }
    sort(str1,str1+j);
    for(int i=j-1;i>=0;i--) cout<<str1[i];
    cout<<'\n';
    return 0;
}
