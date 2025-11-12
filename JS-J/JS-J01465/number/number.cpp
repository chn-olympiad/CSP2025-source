#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int a,int b){
    return b<a;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int n;
    cin>>s;
    n=s.size();
    memset(a,-1,sizeof(a));
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i]-'0';
        }
    }
    sort(a,a+n,cmp);
    int i=0;
    if(a[i]==0){
        cout<<0;
        return 0;
    }
    while(a[i]!=-1){
        cout<<a[i];
        i++;
    }
    return 0;
}
