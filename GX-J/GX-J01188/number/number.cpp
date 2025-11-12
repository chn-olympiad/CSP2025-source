#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

//freopen("number.in","w","stdin");
//freopen("number.out","r","stdout");
int ac=0;
int bakk[1005];
bool cmt(int a,int b)
{
    if(a<b) return true;
    else return false;

}
int main()
{
    string n;
    string a;
    cin>>n;
    for(int i=0;i<n.size();i++)
    {
        if(n[i]>='0' && n[i]<='9')
        {

            int yop = n[i]-'0';
            bakk[i]=yop;
            ac++;
        }
    }
    sort(bakk,bakk+ac+1,cmt);
    for(int i=1;i<=ac;i++)
    {
        cout<<bakk[i];

    }
    return 0;
}
