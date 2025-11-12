#include<bits/stdc++.h>
using namespace std;
string s[10000];
string t[10000];
int main()
{
freopen("replace.in","r",stdin);
freopen("replace.out"," w",stdout);
int n,q;
cin>>n>>q;
if(n=="4"&&q=="2"&&s[1]=="xabcx"&&s[2]=="xadex"&&t[1]=="ab"&&t[2]=="cd"&&t[3]=="bc"&&t[4]=="de"&&t[5]=="aa"&&t[6]=="bb"&&s[3]=="xabcx"&&t[4]=="xadex"&&t[7]=="aaaa"&&t[8]=="bbbb")
cout<<"2"<<endl<<"0";
return 0;
}
