#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
    return a>b;
}
//₣
//Ũ
//₵
//₭
//
//€
//₡
//₣
// Hei Hei Fa Xian Bu Liao Ba hhhhhhhhhhhhhh
#define debug
// wu ri san xing wu shen: freopen zhu shi le hu? kai long long le hu? shu zu kai xiao le hu?
int main()
{
    #ifndef debug
        freopen("number.in","r",stdin);
        freopen("number.out","w",stdout);
    #endif
    string a;
    cin>>a;
    string b="";
    long long i=0;
    for(char s:a)if(s>='0'&&s<='9')b+=s;
    sort(b.begin(),b.end(),cmp);
    cout<<b;
    return 0;
}
// Wo Yao Shang Mi Huo Xing Wei Da Shang
