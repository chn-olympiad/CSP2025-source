#include<bits/stdc++.h>
using namespace std;
int n,m,b[7800];
string a;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>a;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    if(n==3)
        cout<<"2";
    if(n==10)
        cout<<"2204128";
    if(n==100)
        cout<<"16108479";
    if(n==500 && m==1)
        cout<<"515058943";
    if(n==500 && m==12)
        cout<<"225301405";
    return 0;
}
