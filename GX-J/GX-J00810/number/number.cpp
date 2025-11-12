#include <bits/stdc++.h>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
ios::sync_with_stdio(false);
cin>>s;
int a[s.length()+5]={0};
int m=0,n=0;
for(int i=0;i<s.length();i++){
    if(s[i]>=48 and s[i]<=57){
        a[m]=s[i]-48;
        m++;
    }
}
sort(a,a+m);
int w=pow(10,m);
//cout<<w<<endl;
int sum=0;
//for(int i=0;i<m;i++){
//    cout<<a[i]<<" ";
//}
//cout<<endl;
for(int i=m;i>=0;i--){
    sum=sum+a[i]*w;
    w=w/10;
}
cout<<sum;


















return 0;
}










