#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string j;
long long k=0;
cin>>j;
int a[100001];
int v=0;
for(int i=0;i<=j.size();i++)
{
    if(j[i]-'0'<=9&&j[i]-'0'>=0)
    {
        a[v]=j[i]-'0';
        v++;
    }
}

sort(a,a+v,cmp);
for(int i=0;i<v;i++){
    k*=10;
    k+=a[i];
}
cout<<k;
return 0;
}
