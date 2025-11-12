#include<bits/stdc++.h>
using namespace std;
char a[1000001];
int b[1000001],f,j=0;
int pai(int x)
{
    for(int i=0;i<x-1;i++)
    {
        for(int k=i+1;k<x;k++)
        {
            if(b[k]>b[i])
            {
                swap(b[k],b[i]);
            }
        }
    }
    return 0;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    cin>>a;
    f=strlen(a);
    for(int i=0;i<f;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            b[j]=int(a[i]-'0');
            j++;
        }
    }
    pai(j);
    for(int i=0;i<j;i++)
    {
        cout<<b[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
