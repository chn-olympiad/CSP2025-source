#include<bits/stdc++.h>
using namespace std;
long long n,a[5050],s;
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
if(n==3&&a[0]+a[1]>a[2]&&a[1]+a[2]>a[0]&&a[0]+a[2]>a[1])s++;
//sanbianxing
if(n==4&&a[0]+a[1]>a[2]&&a[1]+a[2]>a[0]&&a[0]+a[2]>a[1])s++;
if(n==4&&a[0]+a[1]>a[3]&&a[1]+a[3]>a[0]&&a[0]+a[3]>a[1])s++; 
if(n==4&&a[0]+a[2]>a[3]&&a[2]+a[3]>a[0]&&a[0]+a[3]>a[2])s++; 
if(n==4&&a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2])s++; 
if(n==4&&a[0]+a[1]+a[2]+a[3]-max(a[0],max(a[1],max(a[2],a[3])))>2*max(a[0],max(a[1],max(a[2],a[3]))))s++;
//sibianxing
if(n==5&&a[0]+a[1]>a[2]&&a[1]+a[2]>a[0]&&a[0]+a[2]>a[1])s++;
if(n==5&&a[0]+a[1]>a[3]&&a[1]+a[3]>a[0]&&a[0]+a[3]>a[1])s++; 
if(n==5&&a[0]+a[1]>a[4]&&a[1]+a[4]>a[0]&&a[0]+a[4]>a[1])s++; 
if(n==5&&a[0]+a[2]>a[3]&&a[2]+a[3]>a[0]&&a[0]+a[3]>a[2])s++; 
if(n==5&&a[0]+a[2]>a[4]&&a[2]+a[4]>a[0]&&a[0]+a[4]>a[2])s++; 
if(n==5&&a[0]+a[3]>a[4]&&a[3]+a[4]>a[0]&&a[0]+a[4]>a[3])s++; 
if(n==5&&a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2])s++;
if(n==5&&a[1]+a[2]>a[4]&&a[2]+a[4]>a[1]&&a[1]+a[4]>a[2])s++;
if(n==5&&a[1]+a[3]>a[4]&&a[3]+a[4]>a[1]&&a[1]+a[4]>a[3])s++;
if(n==5&&a[2]+a[3]>a[4]&&a[3]+a[4]>a[2]&&a[2]+a[4]>a[3])s++;
if(n==5&&a[0]+a[1]+a[2]+a[3]-max(a[0],max(a[1],max(a[2],a[3])))>2*max(a[0],max(a[1],max(a[2],a[3]))))s++;
if(n==5&&a[0]+a[1]+a[2]+a[4]-max(a[0],max(a[1],max(a[2],a[4])))>2*max(a[0],max(a[1],max(a[2],a[4]))))s++;
if(n==5&&a[0]+a[1]+a[3]+a[4]-max(a[0],max(a[1],max(a[3],a[4])))>2*max(a[0],max(a[1],max(a[3],a[4]))))s++;
if(n==5&&a[0]+a[4]+a[2]+a[3]-max(a[0],max(a[4],max(a[2],a[3])))>2*max(a[0],max(a[4],max(a[2],a[3]))))s++;
if(n==5&&a[4]+a[1]+a[2]+a[3]-max(a[4],max(a[1],max(a[2],a[3])))>2*max(a[4],max(a[1],max(a[2],a[3]))))s++;
//wubianxing
cout<<s%988244353;
return 0;
}
