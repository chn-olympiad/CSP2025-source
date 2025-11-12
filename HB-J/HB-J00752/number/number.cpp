#include <bits/stdc++.h>
using namespace std;
char c[1000005];
int a[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    if(s.size()==1)
        cout<<s;
    else{
        int x=1;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                c[x]=s[i];
                x++;
            }
        }
        for(int i=1;i<=x;i++){
            if(c[i]=='0')
                a[i]=0;
            if(c[i]=='1')
                a[i]=1;
            if(c[i]=='2')
                a[i]=2;
            if(c[i]=='3')
                a[i]=3;
            if(c[i]=='4')
                a[i]=4;
            if(c[i]=='5')
                a[i]=5;
            if(c[i]=='6')
                a[i]=6;
            if(c[i]=='7')
                a[i]=7;
            if(c[i]=='8')
                a[i]=8;
            if(c[i]=='9')
                a[i]=9;
        }
        sort(a,a+x+1);
        for(int i=x;i>=2;i--){
            cout<<a[i];
        }
    }
    return 0;
}
