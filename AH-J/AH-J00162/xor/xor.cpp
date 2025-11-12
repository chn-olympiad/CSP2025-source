#include<iostream>
using namespace std;
int zh10(char x)
{
    char num[1000]={},v[1000]={};
    int k=0;
    for(int i=0;i<strlen(x);i++)
    {
            num[i]=x[i]%n;
    }
    for(int j=strlen(x);j>=0;j++)
    {
        v[k]=num[j];
        k++;
    }
    return v;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n;
    char a;
    cin>>n;
    for(int h=0;h<n;h++)
    {
        cin >>a[h];
    }
    for(int g=0;g<n;g++)
    {
        cout <<v;
    }
    return 0;
}
