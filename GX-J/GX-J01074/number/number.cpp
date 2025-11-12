#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[10],q=0;
    cin>>s;
    int z=s.size();
    for(int i=1;i<=z;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i];
            q++;
            }
    }
    for(int i=1;i<=q;i++){
        if(a[i]<a[i+1]){
            a[i]=a[i+1];
            a[i+1]=a[i];
        }
        cout<<a[i];
    }
    return 0;
}
