#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
if(a>b) return true;
else return false;}
int main(){
   freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
int a[1000002];
string s;
cin>>s;
int m=1;
for(int i=0;i<s.size();i++)
    if(s[i]>='0'&&s[i]<='9'){
            int c=s[i]-'0';
        a[m]=c;
        m++;

    }
sort(a+1,a+m+1,cmp);
for(int i=1;i<=m-1;i++)
    cout<<a[i];
return 0;
}
