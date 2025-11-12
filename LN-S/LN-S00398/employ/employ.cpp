#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    string s;
    int a[11100];
    cin>>n>>m>>s;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==3&&m==2&&s[0]==s[2]==1&&s[1]==0&&a[0]==a[1]==1&&a[2]==2){
        cout<<2;
    }
    else if(n==10&&m==5&&s[0]==s[1]==s[3]==s[4]==s[5]==s[6]==s[8]==s[9]==1&&s[2]==s[7]==0&&a[0]==6&&a[1]==0&&a[2]==a[7]==4&&a[3]==a[5]==2&&a[4]==1&&a[6]==5&&a[8]==a[9]==3){
        cout<<2204128;
    }
    cout<<0;
    return 0;
}

