#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len=s.length();
    int num[len]={0};
    int cnt=0;
    for(char ch:s) if(ch>='0'&&ch<='9') num[cnt++]=ch-'0';
    sort(num,num+cnt,greater<int>());
    for(int i=0;i<cnt;i++) cout<<num[i];
    cout<<endl;
    return 0;
}
