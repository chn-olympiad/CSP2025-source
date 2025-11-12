#include<bits/stdc++.h>
using namespace std;

int a[1000010],len=0;
int n;
string s;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    s=" "+s;
    for(int i=1;i<=n;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++len]=s[i]-'0';
        }
    }
    sort(a+1,a+len+1);
    for(int i=len;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
