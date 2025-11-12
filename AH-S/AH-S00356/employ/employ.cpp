#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
#define N 10001

using namespace std;

long i,j=0;
long m,n=0;
long p[1000]={0};
string s;
long c[1000]={0};
long c2[1000]={0};
long hard[1000]={0};
long result1,number1;
/*int cmp(int a,int b){
    if(a>b){
        return a>b;
    }
}*/
int main(){

freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
fclose(stdin);
fclose(stdout);

std::cin>>n>>m;
std::getline(cin,s);
for(i=1;i<=n;i++){
    cin>>c[i];
    c[i]=c2[i];
}
//for(i=0;i<=s.size();i++){
for(i=1;i<=n;i++){
    if(s[i]=='1'){
        number1++;
    }
}
sort(c2+0,c2+n);
result1=n;
for(i=1;i<=n;i++){
    if(s[i]==0&&c2[i]<=c2[i+1]){
        result1--;
    }
}
cout<<result1 % 998244353;
return 0;
}
