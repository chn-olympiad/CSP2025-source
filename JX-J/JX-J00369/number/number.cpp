#include<bits/stdc++.h>
using namespace std;
string s,sum;
int a[1000005],cnt;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
            a[++cnt]=((int)s[i]-'0');
        }
    }
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=cnt;i++){
        a[i]=((char)a[i]+'0');
    }
    for(int i=1;i<=cnt;i++){
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}
