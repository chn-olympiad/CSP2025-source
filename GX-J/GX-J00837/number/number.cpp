#include<bits/stdc++.h>
using namespace std;
int a[10000005],n=1;
string s,sum;
bool f(int  x,int  y){
return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]<='9'&&s[i]>='0'){
            a[n]=s[i]-'0';
            n++;
        }
    }
    sort(a+1,a+n+1,f);

    for(int i=1;i<n;i++){
        sum+=a[i]+'0';
    }
    cout<<sum;
}
