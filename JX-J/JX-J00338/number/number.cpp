#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in",'r',stdin);
    freopen("number.out",'w',stdout);
    string s;
    long a[1000001];
    cin>>s;
    int len=s.size();
    int p=0;
    long h=0;
    for(int i=0;i<=len-1;i++){
        if(s[i]<=57&&s[i]>=48){
                p++;
                a[p]=s[i]-48;
        }
    }
    for(int i=0;i<=p-1;i++){
        for(int j=1;j<=p-i;j++){
            if(a[j]<a[j+1]) swap(a[j],a[j+1]);
        }
    }
    for(int i=1;i<=p;i++){
        cout<<a[i];
    }
    return 0;
}
