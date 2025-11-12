#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int s[N];
string b;
int main(){
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    cin>>s[N];
    b=s[N];
    for(int i=1;i<=b.size();i++){
        int a[i];
        if(s[i]>=1&&s[i]<=9){
            a[i]=s[i];
        }else{
            continue;
        }
        if(b.size()==1){
            if(s[i]>=1&&s[i]<=9){
                cout<<s[i];
                return 0;
            }
        }else if(a[i]<a[i-1]){
            a[i-1]=a[i];
            a[i]=a[i-1];
        }
        cout<<a[i];
    }
    return 0;
}
