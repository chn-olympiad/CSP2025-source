#include<bits/stdc++.h>
using namespace std;
string s[100];
int r,i,j,z,sum=0;
int a[10]={1,2,3,4,5,6,7,8,9};
bool b[100];
int c[100];
int print();
void search(int k);
bool number(int x);
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    for(int i=1;i<=10;i++)
    {
        cin>>s[i];
    }
    search(1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
bool number(int x)
{


    for(int n=0;n<10;n++)
    {
        if(x==a[n])
        {
            sum++;
            return true;
        }
    }

}
void search(int k)
{
    for(int i=0;i<r;i++)
    {
        if(!b[i]&&!number(s[i]))
        {
            s[k]=s[i];
            b[k]=1;
            if (k==sum) s[k]=c[i];
            else return search(k+1);
            b[k]=0;
        }
    }
}
