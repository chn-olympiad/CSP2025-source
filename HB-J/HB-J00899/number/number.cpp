#include<bits/stdc++.h>
using namespace std;
string s,tzb="0123456789";
int a[11000],b=0,c;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>s;
int l=s.size();
for(int i=0;i<l;i++)
{
    for(int j=0;j<10;j++)
    {
        if(s[i]==tzb[j]){
            a[b]=j;
            b++;
        }
    }//1d2 10
}
    for(int i=0;i<b;i++){
        for(int j=0;j<b;j++)
        {
            if(a[j]<a[j+1])
            {
                c=a[j];
                a[j]=a[j+1];
                a[j+1]=c;
            }
        }
    }
    //cout<<b;
    if(a[0]!=0){
    for(int i=0;i<b;i++){
         cout<<a[i];
    }
    }
    else
    cout<<"0";
    return 0;
}
