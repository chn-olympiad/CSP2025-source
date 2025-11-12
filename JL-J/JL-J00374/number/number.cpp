#include <bits/stdc++.h>
using namespace std;

char s[1000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int c=0;
    string a;
    cin>>a;
    int z=a.size();
    for(int i=0;i<=z+1;i++){
        if(a[i]<'a'||a[i]>'z'){
            s[i]=a[i];
            c+=1;
        }
    }
    sort(s,s+c);
    reverse(s,s+c);
    for(int i=0;i<=c;i++){
        cout<<s[i];
    }
    return 0;
}
