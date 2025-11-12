#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
    string a;
    int s[1000005];
    int n;
    cin>>a;
    for(int i=0;i<=a.size();i++){
        if(a[i]>='0'||a[i]<='9'){
            s[i+1]=a[i]-'0';
        }
    }
    n=s.size();
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<=n;i++){
        cout<<s[i];
    }
return 0;
}
