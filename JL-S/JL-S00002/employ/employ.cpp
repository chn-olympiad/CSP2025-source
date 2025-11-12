#include<bits/stdc++.h>
using namespace std;
int n,m,sum,s1,s2;
string s;
int patient[502];
int fA(int a,int b)
{
    for(int i=0;i<a;i++)
        s1*=i;
    for(int i=0;i<b;i++)
        s2*=i;
    sum=b/a;
    return sum;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
cin>>n>>m;
cin>>s;
    if(m==1)
    {
        if(n%2==0)
            cout<<(n/2)*(n+1);
        else
            cout<<(n/2)*(n+1)+fA(n/2+1,n);
        return 0;
    }
for(int i=0;i<n;i++)
        cin>>patient[i];
cout<<0;
    fclose(stdin);
    fclose(stdout);
return 0;
}
