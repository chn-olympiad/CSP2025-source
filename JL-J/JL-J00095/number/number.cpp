#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],b;
int main(){
  //  freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    cin>>s;
    if(s.size()==1){
        cout<<s;
        return 0;
    }
    for(int i=1;i<=s.size();i++)
    {
        a[i]=s[i];
    }
    for(int i=1;i<=s.size();i++){
        if(a[i]<a[i+1]){
            b=a[i];
            a[i]=a[i+1];
            a[i+1]=b;
        }

    }
    for(int i=1;i<=s.size();i++){
        cout<<a[i];
    }
    return 0;
}
