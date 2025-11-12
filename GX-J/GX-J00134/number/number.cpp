#include<iostream>
#include<string>
long long a[100005],t=0;
using namespace std;
int main(){
    string s;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            t++;
            a[t]=s[i]-48;
        }
    }
    for(int i=1;i<=t;i++){
        for(int j=i;j<=t;j++){
            if(a[i]<a[j])
                swap(a[i],a[j]);
        }
    }
    for(int i=1;i<=t;i++){
        cout<<a[i];
    }
    return 0;
}
