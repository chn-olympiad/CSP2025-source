#include<bits/stdc++.h>
using namespace std;
string s;
int a[100001],len,j=1;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    len=s.size();
    for(int i=0;i<=len;i++)
        if(isdigit(s[i])){
            a[j]=s[i]-'0';
            j++;
        }
    sort(a+1,a+j,cmp);
    for(int i=1;i<j;i++)
        cout<<a[i];
    return 0;
}
