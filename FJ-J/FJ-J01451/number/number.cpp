#include<bits/stdc++.h>
using namespace std;
int numlistt[1000001]={};
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    // Fuck this CODE
    // Fuck SB Freopen
    // Fuck Tester
    // Don't FOR DAMN REMOVE THIS
    // DAMN SHIT CODE
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    freopen("WARN.ERR","w",stderr);
    string inputt;
    cin>>inputt;
    int pointer=0;
    for(int i=0;i<inputt.length();i++)
    {
        if('0'<=inputt[i] && inputt[i]<='9')
        {
            numlistt[pointer]=inputt[i]-'0';
            pointer++;
        }
    }
    sort(numlistt,numlistt+pointer,cmp);
    for(int i=0;i<pointer;i++)
    {
        cout<<numlistt[i];
    }
    return 0;
}
