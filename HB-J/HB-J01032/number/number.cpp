#include<iostream>
#include<string>
using namespace std;
bool  isnumber(string s,int i)
{

    if(s.substr(i,1)=="0"||s.substr(i,1)=="1"||s.substr(i,1)=="2"||s.substr(i,1)=="3"||s.substr(i,1)=="4"||s.substr(i,1)=="5"||s.substr(i,1)=="6"||s.substr(i,1)=="7"||s.substr(i,1)=="8"||s.substr(i,1)=="9")
        return true;
    else
        return false;
}
string fs(string s)
{
    string tmp=s.substr(0,1);
    for(int i=0;i<s.length();i++)
        if(tmp<s.substr(i,1))
            tmp=s.substr(i,1);
    return tmp;

}
int find(string str,string key)
{
    for(int i=0;i<str.length();i++)
        if(key==str.substr(i,1))
            return i;
    return -1;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    string t="";
    for(int i=0;i<s.length();i++)
        if(isnumber(s,i))
            t+=s.substr(i,1);
    //Now We Let t Only Numbers,Now Let Sort It.
    string answer="";
    for(;!t.empty();)
    {
        string flag=fs(t);
        answer+=flag;
        t.replace(find(t,flag),1,"");

    }
    cout<<answer;
    return 0;
}
