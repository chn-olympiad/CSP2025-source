#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
string s;
int n,a[1000100];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)if(isdigit(s[i]))a[n++]=s[i]-'0';
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)cout<<a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;

}
