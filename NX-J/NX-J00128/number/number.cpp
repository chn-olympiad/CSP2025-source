#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;

    int n=0;
    for(int i=0;i<a.size();i++){
        if(!(a[i]>='a'&&a[i]<='z')){
            n++;
        }
    }
    char s[n];
    int x=0;
    for(int i=0;i<a.size();i++){
        if(!(a[i]>='a'&&a[i]<='z')){
            s[x]=a[i];
            x++;
        }
    }

    sort(s,s+n+2,cmp);
    for(int i=0;i<n;i++){
        cout<<s[i];
    }
    return 0;
}
