#include<bits/stdc++.h>
using namespace std;
int s[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int n=1;
    cin>>a;
    int m=a.size();
    for(int i=0;i<m;i++){
        if('0'<=a[i]&&a[i]<='9'){
            s[n]=int(a[i])-48;
            n++;
        }
    }
    n--;
    sort(s+1,s+n+1);
    for(int i=n;i>=1;i--){
        cout<<s[i];
    }
    return 0;
}
