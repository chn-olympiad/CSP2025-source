#include<bits/stdc++.h>
using namespace std;
string s;
string a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l1=s.size();
    int l2=0;
    char c;
    for(int i=0;i<=l1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            c=s[i];
            a=a+c;
            l2++;
        }
    }
    for(int i=0;i<=l2;i++){
        for(int j=i+1;j<=l2;j++){
            if(a[j]>a[i]){
                c=a[i];
                a[i]=a[j];
                a[j]=c;
            }
        }
    }
    cout<<a;
    return 0;
}
