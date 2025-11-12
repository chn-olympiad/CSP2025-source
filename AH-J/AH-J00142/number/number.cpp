#include<bits/stdc++.h>
using namespace std;
int s[1000010];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n=1;
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0' && a[i]<='9'){
            s[n]=(a[i]-'0');
            n++;
        }
    }
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<n;i++)cout<<s[i];
    return 0;
}
