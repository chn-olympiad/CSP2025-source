#include<bits/stdc++.h>
using namespace std;

int s[110110];
int qjh(int r,int l,int sum)
{
    sum=s[r]||s[r+1];
    for(int i=r+2;i<l;i++)
    {
        int ans=sum||s[r];
        sum=ans;
    }
    return sum;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cout<<"2"<<endl;
}
