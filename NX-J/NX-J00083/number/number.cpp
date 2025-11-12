#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10000010],n,cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size()-1;
    for(int i=0;s[i];i++){
       if(s[i]!='0'&&s[i]!='1'&&s[i]!='2'&&s[i]!='3'&&s[i]!='4'&&s[i]!='5'&&s[i]!='6'&&s[i]!='7'&&s[i]!='8'&&s[i]!='9'){
            s[i]='a';
            cnt++;
       }
    }
    for(int i=0;s[i];i++){
        if(s[i]!='a'){
            a[i]=s[i]-'0';
        }
        else{
            continue;
        }
    }
    sort(a,a+n+2);
    for(int i=n+1;i>=0;i--){
       if(a[i]==0&&cnt>=0){
            cnt--;
            continue;
       }
       cout<<a[i];
    }
    return 0;
}
