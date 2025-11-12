#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6+7;
string s;
int num[N],cnt=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.length();
    for(int i=0;i<l;i++){
        if('0'<=s[i]&&s[i]<='9')num[cnt++]=s[i]-'0';
    }
    sort(num+1,num+cnt);
    for(int i=cnt-1;i>=1;i--)cout<<num[i];
    return 0;
}
