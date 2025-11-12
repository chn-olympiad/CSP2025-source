#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size();
    int a[1000005],cnt=1;
    for(int i=0;i<n;i++){
        if(int(s[i])>=48&&int(s[i])<=57){
            a[cnt]=int(s[i])-48;
            cnt++;
        }
    }
    for(int i=1;i<=cnt;i++){
        for(int j=i;j<=cnt;j++){
            if(a[i]<a[j]){
                int q=a[i];
                a[i]=a[j];
                a[j]=q;
            }
        }
    }
    for(int i=1;i<cnt;i++){
        cout<<a[i];
    }
    return 0;
}
